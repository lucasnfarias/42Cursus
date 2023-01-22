/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lniehues <lniehues@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:45:05 by lniehues          #+#    #+#             */
/*   Updated: 2023/01/22 17:08:58 by lniehues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <cstdio>
#include <fstream>
#include <sstream>

/*
  TO-DO:

  - read the subject to better understand the requirements

  - read config file
    - also set a default config file if not config file is given

  - parse config file
    - check what is configurable from nginx perspective - subject Configuration file section
    - e.g. multiple ports, root, ...

  - set default error pages
  - check fork for CGI operations
  - must be able to upload files
  - use javascript scripts or other to test this mothergfucker
  - ...
*/

int main(int argc, char **argv) {
  int server_fd;
  int new_socket;

  struct sockaddr_in address;
  int address_len = sizeof(address);
  int PORT = 8080;

  if (argc > 1)
    PORT = atoi(argv[1]);

  long valread;

  memset(address.sin_zero, '\0', sizeof address.sin_zero);

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(PORT);

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    std::cerr << "cannot create socket" << std::endl;
    return 0;
  } else std::cout << "socket created!" << std::endl;

  if (bind(server_fd, (struct sockaddr *)&address,sizeof(address)) < 0) {
    std::cerr << "bind failed" << std::endl;
    return 0;
  } else std::cout << "bind successful!" << std::endl;

  if (listen(server_fd, 10) < 0) {
      std::cerr << "listen failed!" << std::endl;
      exit(EXIT_FAILURE);
  } else std::cout << "listening on port " << PORT << "..." << std::endl;

  while (1) {
    printf("\n+++++++ Waiting for new connection ++++++++\n\n");

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&address_len)) < 0) {
      std::cerr << "accept failed!" << std::endl;
      exit(EXIT_FAILURE);
    }

    char buffer[30000] = {0};

    valread = recv(new_socket , buffer, 30000, 0);

    if (valread == 0) printf("No bytes are there to read");
    else if (valread == -1) strerror(errno);
    else printf("%s\n", buffer);

    std::string response = "HTTP/1.1 200 OK\nContent-Type: text/html\n";
    std::ifstream myfile ("./www/index.html");
    std::string file_content;
    std::string tmp;
    std::stringstream content_length;

    if (myfile.is_open()) {
      while (myfile) {
        tmp = myfile.get();
        if (myfile) file_content = file_content + tmp;
      }
    } else std::cerr << "can't open file :(" << std::endl;

    response.append("Content-Length: ");
    content_length << file_content.length();
    response = response + content_length.str()  + "\n\n";
    response.append(file_content);

    send(new_socket , response.c_str() , response.length(), 0);
    write(0 , response.c_str() , response.length());
    printf("------------------Hello message sent-------------------\n");

    close(new_socket);
  }

  return 0;
}
