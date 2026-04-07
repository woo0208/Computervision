# 실습과제 1

**1. MPEG-4**
* **개념:** ISO/IEC 산하 MPEG(Moving Picture Experts Group)에서 제정한 멀티미디어 압축 표준입니다.
* **특징:** 화면 전체를 픽셀 단위로만 압축하는 방식을 넘어, 영상 내의 객체(Object)를 독립적으로 부호화할 수 있는 개념을 도입했습니다. 이산 코사인 변환(DCT)과 양자화(Quantization)로 공간적 중복성을 줄이고, 움직임 보상(Motion Compensation)으로 시간적 중복성을 줄이는 기본 원리를 따릅니다.
* **OpenCV 활용:** 초창기 영상 처리 시스템에서 주로 사용된 베이스 규격입니다.

**2. DivX (Digital Video Express)**
* **개념:** MPEG-4 Part 2 기술을 기반으로 상용화된 비디오 코덱입니다.
* **특징:** 원본 DVD 화질에 버금가는 품질을 유지하면서 파일 용량을 획기적으로 줄일 수 있어 널리 쓰였으나, 상용(독점) 라이선스 정책으로 인해 개발자들에게 폐쇄적인 한계가 있었습니다.

**3. Xvid**
* **개념:** DivX의 상용화 정책에 반발하여 오픈소스 진영에서 개발한 MPEG-4 Part 2 호환 코덱입니다. ('DivX'를 역순으로 표기한 이름입니다.)
* **특징:** 오픈소스이면서도 뛰어난 압축률과 화질을 제공합니다.
* **OpenCV 활용:** 압축 속도가 빠르고 호환성이 우수하여, `cv::VideoWriter`로 동영상을 저장할 때 `cv::VideoWriter::fourcc('X', 'V', 'I', 'D')` 형태로 가장 기본적이고 안정적으로 사용됩니다.

**4. H.264 (MPEG-4 Part 10 / AVC)**
* **개념:** ITU-T와 MPEG이 공동 개발한 표준으로, AVC(Advanced Video Coding)라고도 불립니다. 현재 비디오 스트리밍 및 저장 매체의 표준입니다.
* **특징:** 다중 참조 프레임(Multiple Reference Frames)을 지원하고, 16x16 매크로블록을 더 잘게 쪼개는 가변 블록 크기 움직임 보상(Variable Block-Size Motion Compensation)을 수행하여 압축 효율을 극대화했습니다.
* **OpenCV 활용:** `cv::VideoWriter::fourcc('X', '2', '6', '4')`로 지정합니다. 압축 효율은 훌륭하지만 연산량이 많아 시스템 리소스(CPU/GPU)가 요구됩니다.

**5. H.265 (HEVC)**
* **개념:** H.264의 후속 표준인 HEVC(High Efficiency Video Coding)입니다. 4K, 8K 이상의 초고해상도 영상 처리에 최적화되어 있습니다.
* **특징:** 고정된 매크로블록 대신, 영상의 복잡도에 따라 가변적으로 분할되는 코딩 트리 단위(CTU: Coding Tree Unit, 최대 64x64)를 채택했습니다. H.264와 동일 화질 대비 비트레이트를 약 50% 절감하지만, 수학적 연산 복잡도가 매우 높아 하드웨어 가속이 사실상 필수적입니다.

---

# 실습과제 2 - 실행 결과

<img width="1281" height="510" alt="image" src="https://github.com/user-attachments/assets/03a6519b-f12c-4971-a821-04c5bfc1251e" />


---

# 실습과제 3 - 실행 결과

<img width="1925" height="510" alt="image" src="https://github.com/user-attachments/assets/0d053973-79ec-4cfb-b90c-a5e15687e728" />


---

# 실습과제 4 - 실행 결과

<img width="641" height="507" alt="image" src="https://github.com/user-attachments/assets/b36c4a57-4cb3-4d15-b6b4-020399886de0" />
<img width="906" height="846" alt="image" src="https://github.com/user-attachments/assets/401614af-45a6-4d9f-8ba6-92a339616fa6" />


---

# 실습과제 5 - 실행 결과
<img width="642" height="514" alt="image" src="https://github.com/user-attachments/assets/8243db80-8514-495f-a164-1d45071d210b" />
<img width="676" height="513" alt="image" src="https://github.com/user-attachments/assets/b946c5d5-2841-4fc4-a323-f54ad3e8c597" />

