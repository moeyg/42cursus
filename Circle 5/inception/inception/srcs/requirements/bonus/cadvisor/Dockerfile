FROM alpine:3.16

ARG CADVISOR_VERSION=0.46.0

RUN apk update && \
    apk add --no-cache wget git && \
    git clone https://github.com/jjongs2/cadvisor-mirror.git && \
    mv cadvisor-mirror/cadvisor-v${CADVISOR_VERSION}-linux-amd64 /usr/local/bin/cadvisor && \
    rm -rf cadvisor-mirror/ && \
    wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/bin/dumb-init

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD ["cadvisor"]
