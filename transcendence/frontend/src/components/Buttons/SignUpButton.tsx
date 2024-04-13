import { Button, Group, Modal } from '@mantine/core';
import { FC, useState } from 'react';
import { Link } from 'react-router-dom';
import { RegisterForm } from '../Forms/RegisterUserForm';

const SignUpButton: FC = () => {
  const [opened, setOpened] = useState(false);

  return (
    <>
      <Modal opened={opened} onClose={() => setOpened(false)}>
        <RegisterForm />
      </Modal>

      <Group position='center'>
        <Link to='/login'>
          <Button color='secondary' onClick={() => setOpened(false)}>
            Sign Up
          </Button>
        </Link>
      </Group>
    </>
  );
};

export default SignUpButton;
