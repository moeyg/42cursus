FROM alpine:3.16

ARG FTP_USR \
    FTP_PWD

RUN apk update && \
    apk add --no-cache vsftpd wget && \
    wget -O /usr/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.5/dumb-init_1.2.5_x86_64 && \
    chmod +x /usr/bin/dumb-init

RUN adduser ${FTP_USR} --disabled-password --gecos "" --home /home/${FTP_USR} --shell /bin/false && \
    echo "${FTP_USR}:${FTP_PWD}" | /usr/sbin/chpasswd

COPY requirements/bonus/vsftpd/tools/script.sh /tmp/script.sh
RUN chmod +x /tmp/script.sh

EXPOSE 21

ENTRYPOINT [ "/usr/bin/dumb-init", "--" ]

CMD [ "sh", "/tmp/script.sh" ]
