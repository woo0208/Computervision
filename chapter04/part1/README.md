# 실습과제 1

## 1. API (Application Programming Interface)
* **정의**: 응용 프로그램에서 운영체제나 시스템의 기능을 제어할 수 있게 만든 인터페이스(규칙과 약속의 모음)입니다.
* **CV 관점**: OpenCV의 `VideoCapture`나 `imshow` 같은 함수들이 바로 API입니다. 개발자는 카메라 하드웨어의 복잡한 물리적 제어 방식을 몰라도, OpenCV가 제공하는 API(`cap >> frame;`)만 호출하면 쉽게 영상을 가져올 수 있습니다.

## 2. V4L (Video4Linux / V4L2)
* **정의**: 리눅스(Linux) 운영체제 환경에서 실시간 비디오 캡처를 지원하는 디바이스 드라이버 및 API의 모음입니다.
* **CV 관점**: 라즈베리파이나 우분투(Ubuntu) 같은 리눅스 환경에서 OpenCV로 USB 웹캠이나 카메라 모듈을 구동할 때 기본적으로 사용되는 백엔드입니다. 

## 3. FFMPEG
* **정의**: 오디오 및 비디오를 기록, 변환, 스트리밍하는 데 사용되는 매우 강력한 크로스 플랫폼 오픈소스 멀티미디어 프레임워크입니다.
* **CV 관점**: OpenCV가 `.mp4`, `.avi` 등의 **동영상 파일**을 읽고 쓸 때 가장 핵심적으로 의존하는 라이브러리입니다. 수많은 코덱(Codec)을 내장하고 있어 다양한 포맷의 영상을 디코딩(압축 해제)하여 `Mat` 객체로 변환해 줍니다.

## 4. DirectShow (DShow)
* **정의**: 마이크로소프트(Microsoft)가 개발한 윈도우(Windows)용 레거시 멀티미디어 프레임워크 및 API입니다.
* **CV 관점**: 윈도우 환경에서 웹캠을 연결할 때 오랫동안 표준으로 사용되었습니다. 가끔 윈도우에서 카메라 연결이 지연되거나 해상도 설정이 잘 안 될 때, `VideoCapture cap(0, CAP_DSHOW);` 와 같이 명시적으로 DirectShow API를 호출하도록 강제하여 문제를 해결하기도 합니다.

## 5. MSMF (Microsoft Media Foundation)
* **정의**: DirectShow를 대체하기 위해 마이크로소프트가 도입한 차세대 윈도우 멀티미디어 프레임워크입니다.
* **CV 관점**: 고화질 비디오 형식, 하드웨어 가속(GPU 등) 및 향상된 색상 공간을 지원합니다. 최신 윈도우 환경(Windows 10/11)의 OpenCV에서는 카메라 구동 시 MSMF를 기본 백엔드로 사용하려는 경향이 있습니다. (`CAP_MSMF`)

## 6. GStreamer
* **정의**: 리눅스 및 유닉스 환경에서 주로 사용되는 파이프라인(Pipeline) 기반의 강력한 멀티미디어 프레임워크입니다.
* **CV 관점**: 데이터의 흐름을 레고 블록처럼 연결(Source -> Filter -> Sink)하여 처리합니다. 특히 엔비디아 젯슨(NVIDIA Jetson)과 같은 엣지 디바이스나 드론에서 하드웨어 가속 기반의 고속 영상 처리/네트워크 스트리밍을 구현할 때 OpenCV와 결합하여 필수적으로 사용됩니다. (`CAP_GSTREAMER`)

---

# 실습과제 2 - 실행결과

<img width="1280" height="510" alt="image" src="https://github.com/user-attachments/assets/4dfd597f-b01e-453b-b3a2-fcb4c60d3a37" />


---

# 실습과제 3 - 실행결과


<img width="1450" height="829" alt="image" src="https://github.com/user-attachments/assets/cf208c53-df09-447f-b000-9cac0356106b" />


---

# 실습과제 4 - 실행결과


<img width="1280" height="511" alt="image" src="https://github.com/user-attachments/assets/133b6780-0aab-434f-82f0-a858c32a0eaf" />
