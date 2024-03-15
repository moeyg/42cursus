FROM alpine:3.16

RUN apk update && \
    apk add --no-cache redis wget && \
    sed -i "s|bind 127.0.0.1|#bind 127.0.0.1|g"  /etc/redis.conf && \
    sed -i "s|# maxmemory <bytes>|maxmemory 20mb|g"  /etc/redis.conf && \
    echo "maxmemory-policy allkeys-lru" >> /etc/redis.conf && \
    wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/bin/dumb-init

EXPOSE 6379

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD [ "redis-server" , "/etc/redis.conf" ]
