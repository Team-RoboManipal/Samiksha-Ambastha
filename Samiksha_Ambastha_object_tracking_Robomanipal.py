import cv2 as cv


capture=cv.VideoCapture('football.mp4')
#dynamic object detection
object_detector=cv.createBackgroundSubtractorMOG2(history=10000,varThreshold=100)

while True:
    ret,frame=capture.read()
    height,width,channel=frame.shape
    print(height,width,channel)
    #extracting region of interest
    roi=frame[300:600,0:480]
    
    #frame=cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
    mask=object_detector.apply(roi)
    
    x,mask=cv.threshold(mask,254,255,cv.THRESH_BINARY)
    contours,hierarchy=cv.findContours(mask,cv.RETR_TREE,cv.CHAIN_APPROX_SIMPLE)
    for cnt in contours:
        #calculate area and remove other elements
        area=cv.contourArea(cnt)
        if 50<area<58:
         #cv.drawContours(roi,[cnt],-1,(0,255,0),2)
         (x,y,w,h)=cv.boundingRect(cnt)
         aspect_ratio=float(w)/h
         if 1.5>aspect_ratio>1.05:
          cv.rectangle(roi,(x,y),(x+w,y+h),(0,255,0),1)
    cv.imshow('frame',frame)
    cv.imshow('roi',roi)
    cv.imshow('mask',mask)
    if cv.waitKey(20)&0xFF==ord('d'):
        break
    
capture.release()  
cv.destroyAllWindows() 
     