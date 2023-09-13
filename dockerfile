FROM gcc:11.4.0
WORKDIR /home/app
COPY makefile /home/app/makefile
COPY src /home/app/src
RUN make
ENTRYPOINT ["./main"]
VOLUME [ "/home/app/data" ]
