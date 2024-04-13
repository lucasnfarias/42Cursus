import { DefaultProps, Flex, Stack, Text, UnstyledButton } from '@mantine/core';
import { useHover } from '@mantine/hooks';
import { FC, PropsWithChildren, useEffect, useMemo, useState } from 'react';
import { IChat } from '../../context/ChatContext';
import { useAuthContext } from '../../hooks/useAuthContext';
import { useChatContext } from '../../hooks/useChatContext';
import UserAvatar, { UserAvatarGroup } from '../UserAvatar';

interface ChatItemProps extends DefaultProps {
  chat: IChat;
}

const ChatItem: FC<ChatItemProps> = ({ chat }) => {
  const { user } = useAuthContext();
  const { hovered, ref } = useHover();
  const { activeChat, setActiveChat } = useChatContext();
  const [chatName, setChatName] = useState('');

  useEffect(() => {
    if (chat.type === 'direct') {
      const { firstName, lastName } = chat.users.find(({ id }) => id != user?.id) || {};

      setChatName(firstName ? `${firstName} ${lastName}` : 'Direct Message');
    } else {
      setChatName(chat.name);
    }
  }, [chat, user]);

  const dmFriend = useMemo(() => {
    if (chat.type === 'direct') {
      return chat.users.find(({ id }) => id !== user?.id);
    }
    return null;
  }, [chat, user]);

  const isActiveChat = useMemo(() => activeChat?.id === chat.id, [activeChat, chat]);

  return (
    <UnstyledButton
      onClick={() => {
        setActiveChat(chat);
      }}
      style={{
        width: '98%',
        margin: '8px 0',
      }}
    >
      <Flex
        py='xs'
        pl='sm'
        mih={60}
        align='center'
        ref={ref}
        style={{
          backgroundColor: hovered || isActiveChat ? '#2D2D2D' : 'transparent',
          cursor: 'pointer',
          borderRadius: 4,
          opacity: hovered ? 0.7 : 1,
          border:
            hovered || isActiveChat ? '1px solid rgba(244, 96, 54, 1)' : '1px solid transparent',
        }}
      >
        {dmFriend ? (
          <UserAvatar user={dmFriend} size='md' />
        ) : (
          <UserAvatarGroup users={chat.users} size='md' />
        )}
        <Stack spacing={1} ml={'xs'} justify='start'>
          <Text size='md' weight='bold' color='white'>
            {chatName}
          </Text>
          <Text size='sm' color='grey' truncate maw={250}>
            {chat.lastMessage ?? ''}
          </Text>
        </Stack>
      </Flex>
    </UnstyledButton>
  );
};

const SidebarFriends: FC<PropsWithChildren> = () => {
  const { chats } = useChatContext();

  return (
    <Flex
      direction='column'
      align='center'
      bg='lightBlack'
      h='100%'
      className='custom-scroll-bar'
      style={{ borderRadius: '0 0 0 10px', overflow: 'auto' }}
    >
      {chats.map((chat) => (
        <ChatItem key={chat.id} chat={chat} />
      ))}
    </Flex>
  );
};

export default SidebarFriends;
