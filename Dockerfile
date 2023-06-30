FROM nvcr.io/nvidia/l4t-base:r32.5.0

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && \
    apt-get -y install software-properties-common && \
    apt-get update && \
    add-apt-repository universe && \
    add-apt-repository multiverse && \
    apt-get update && \
    apt-get -y install python3.6 python3-pip python3-dev && \
    apt-get -y install alsa-base alsa-utils pulseaudio libffi-dev curl vim && \
    apt-get -y install gstreamer1.0-tools gstreamer1.0-alsa gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-plugins-base-apps
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata
RUN apt-get -y install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-good1.0-dev libgstreamer-plugins-bad1.0-dev

RUN pip3 install cffi boto3 requests watchdog

RUN apt-get install -y gstreamer1.0-pulseaudio && \
    apt-get install -y sudo

RUN apt-get install -y git gcc make libasound2-dev libsamplerate0-dev libspeexdsp-dev && \
    apt-get install -y libsndfile1-dev libglib2.0-dev dbus libdbus-1-dev libudev-dev libsystemd-dev libcap-dev && \
    apt-get install -y libjson-c-dev intltool libsndfile-dev libbluetooth-dev libsbc-dev libwebrtc-audio-processing-dev libx11-dev