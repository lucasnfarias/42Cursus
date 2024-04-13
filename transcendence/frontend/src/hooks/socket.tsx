import {
  FC,
  PropsWithChildren,
  createContext,
  useCallback,
  useContext,
  useEffect,
  useState,
} from 'react';
import { Socket, io } from 'socket.io-client';
import { IUser } from '../context/AuthContext';
import { useAuthContext } from './useAuthContext';

interface ISocketContext {
  socket: Socket | null;
  socketUsersList: { [userId: number]: SocketUser };
  updateSocketUserStatus(status: socketStatus): void;
}

type socketStatus = 'online' | 'offline' | 'game' | 'chat';
interface SocketUser extends IUser {
  status: socketStatus;
}

const SocketContext = createContext<ISocketContext | null>(null);

export const SocketProvider: FC<PropsWithChildren> = ({ children }) => {
  const { user } = useAuthContext();
  const [socket, setSocket] = useState<Socket | null>(null);
  const [socketUsersList, setSocketUsersList] = useState({} as { [userId: number]: SocketUser });

  useEffect(() => {
    if (!user) return;

    const newSocket = io(process.env.REACT_APP_BACKEND_URL as string, {
      transports: ['websocket'],
      withCredentials: true,
      auth: {
        user: user,
      },
    });

    setSocket((currentSocket) => {
      currentSocket?.disconnect();
      return newSocket;
    });

    newSocket.on('usersList', (usersList: SocketUser[]) =>
      setSocketUsersList(
        usersList.reduce((indexedList, user) => ({ ...indexedList, [user.id]: user }), {}),
      ),
    );
  }, [user]);

  const updateSocketUserStatus = useCallback(
    (status: socketStatus) => {
      if (user) socket?.emit('updateUser', { ...user, status });
    },
    [socket, user],
  );

  return (
    <SocketContext.Provider value={{ socket, socketUsersList, updateSocketUserStatus }}>
      {children}
    </SocketContext.Provider>
  );
};

export const useSocket = () => {
  const context = useContext(SocketContext);

  if (!context) {
    throw Error('useSocket must be used inside an SocketProvider');
  }

  return context;
};
