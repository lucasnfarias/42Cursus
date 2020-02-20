#! /usr/bin/env bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    autoindex_switching.sh                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lniehues <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 14:30:31 by lniehues          #+#    #+#              #
#    Updated: 2020/02/18 14:30:31 by lniehues         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#nginx_file="./nginx.configuration"
nginx_file='/etc/nginx/sites-enabled/default'

grep "autoindex on;" "$nginx_file" > /dev/null
if [ "$?" = "0" ]; then
	echo "Current state of autoindex is ON"
	sed -i 's/autoindex on/autoindex off/g' "$nginx_file"
	autoindex="OFF";
else
	echo "Current state of autoindex is OFF"
	sed -i "s/autoindex off/autoindex on/g" "$nginx_file"
	autoindex="ON";
fi
echo "Switching and restarting server.."
/etc/init.d/nginx restart
echo -e "Autoindex is now $autoindex!"
