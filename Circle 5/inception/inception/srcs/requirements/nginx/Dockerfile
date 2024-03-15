FROM	alpine:3.16
RUN	apk update && \
	apk add --no-cache nginx wget && \
	wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
	chmod +x /usr/bin/dumb-init
EXPOSE	443

ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]

CMD	["nginx", "-g", "daemon off;"]
