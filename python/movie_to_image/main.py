import cv2
import os

videoCapture = cv2.VideoCapture()
current_position = 'data/'
address = 'image/'
paths = os.listdir(current_position)
j = 0
q = 0
n = 0
paths.sort()
print(paths)

for path in paths:
    # a = path.split('.')   imwrite 中路径不能有中文
    #

    if not os.path.exists(address + str(n)):
        os.makedirs(address + str(n))

    print(current_position + path)
    videoCapture.open(current_position + path)
    fps = videoCapture.get(cv2.CAP_PROP_FPS)
    frames = videoCapture.get(cv2.CAP_PROP_FRAME_COUNT)
    # fps是帧率，意思是每一秒刷新图片的数量，frames是一整段视频中总的图片数量。
    print("fps=", fps, "frames=", frames)

    # 十帧取一张图
    for i in range(int(frames)):
        ret, frame = videoCapture.read()
        j = j + 1
        if j % 10 == 0:
            print(i)
            if i > frames:
                break
            frame = cv2.resize(frame, (1280, 720), interpolation=cv2.INTER_AREA)  # 修改为图片默认的尺寸
            name = str(q).zfill(6)
            if not cv2.imwrite(address + str(n) + '/' + name + '.jpg', frame):
                raise Exception("Could not write image")
            q = q + 1
    n = n + 1
