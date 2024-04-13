import { Flex, Space } from '@mantine/core';
import { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';
import { FCWithLayout } from '../../App';
import Layout from '../../components/Layout';
import FriendsListCard from '../../components/Profile/FriendsListCard';
import MatchHistoryCard from '../../components/Profile/MatchHistoryCard';
import ProfileCard from '../../components/Profile/ProfileCard';
import UserStatsCard from '../../components/Profile/UserStatsCard';
import { useSocket } from '../../hooks/socket';
import { useAuthContext } from '../../hooks/useAuthContext';

const Profile: FCWithLayout = () => {
  const { userId } = useParams();
  const { user } = useAuthContext();
  const [currentUserId, setCurrentUserId] = useState<number | undefined>(Number(userId));
  const { socket, updateSocketUserStatus } = useSocket();

  useEffect(() => {
    if (socket) updateSocketUserStatus('online');
  }, [socket]);

  useEffect(() => {
    if (Number(userId) === user?.id) history.replaceState(null, '', '/profile/me');
    if (userId === 'me') setCurrentUserId(user?.id);
    else setCurrentUserId(Number(userId));
  }, [user, userId]);

  return (
    <Flex
      style={{ flex: 1 }}
      direction={{ base: 'column', sm: 'row' }}
      justify='space-around'
      align='start'
      m={32}
      p={{ base: 32, sm: 0 }}
    >
      <Flex direction='column'>
        <ProfileCard userId={currentUserId} />
        <Space h={20} />
        <FriendsListCard userId={currentUserId} />
      </Flex>
      <Flex direction='column'>
        <UserStatsCard userId={currentUserId} />
        <Space h={20} />
        <MatchHistoryCard userId={currentUserId} />
      </Flex>
    </Flex>
  );
};

Profile.getLayout = function getLayout(page) {
  return <Layout imageSrc='/images/stephan-quintet.png'>{page}</Layout>;
};

export default Profile;
