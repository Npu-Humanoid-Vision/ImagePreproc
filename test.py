import cv2

if __name__ == "__main__":
    img = cv2.imread("./CodeByOthers/Data-Augmentation-using-Tensorflow/1.jpg")
    h, w, c = img.shape
    print(h, w)
    center = (w // 2, h // 2) #11
    print(center)
    M = cv2.getRotationMatrix2D(center, -45, 1.0) #12
    rotated = cv2.warpAffine(img, M, (w, h), cv2.INTER_LINEAR, cv2.BORDER_REFLECT_101) #13
    cv2.imshow("233", rotated)
    cv2.waitKey()
    cv2.imwrite("233.jpg", rotated)

