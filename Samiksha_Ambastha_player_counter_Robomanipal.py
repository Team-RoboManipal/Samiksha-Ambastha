import cv2 as cv
import numpy as np

# Open the video capture
capture = cv.VideoCapture('football.mp4')
object_detector=cv.createBackgroundSubtractorMOG2(history=10000,varThreshold=100)

# Define color ranges for the two teams and the green field
first_team_lower = np.array([100, 0, 0])  # Blue
first_team_upper = np.array([140, 255, 255])

second_team_lower = np.array([5, 10, 15])  # Black
second_team_upper = np.array([100, 100, 100])

green_lower = np.array([40, 40, 40])
green_upper = np.array([70, 255, 255])
kernel = np.ones((5, 5), np.uint8)

while True:
    ret, frame = capture.read()
    if not ret:
        break
   
    # Convert the frame to HSV
    roi=frame[300:600,0:480]
    hsv = cv.cvtColor(roi, cv.COLOR_BGR2HSV)
    cv.imshow('hsv',hsv)
    # Create the masks for the first and second teams
    mask_first_team = cv.inRange(hsv, first_team_lower, first_team_upper)
    mask_second_team = cv.inRange(hsv, second_team_lower, second_team_upper)

    # Apply morphological operations to remove noise (dilation and erosion)
    mask_first_team = cv.dilate(mask_first_team, kernel, iterations=1)
    mask_first_team = cv.erode(mask_first_team, kernel, iterations=1)

    mask_second_team = cv.dilate(mask_second_team, kernel, iterations=1)
    mask_second_team = cv.erode(mask_second_team, kernel, iterations=1)
    cv.imshow('mask',mask_first_team)
    cv.imshow('mask2',mask_second_team)
    # Find contours in the mask of the first team (blue)
    contours_first_team, _ = cv.findContours(mask_first_team, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)

    # Find contours in the mask of the second team (black)
    contours_second_team, _ = cv.findContours(mask_second_team, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)

    # Initialize counters for players
    counter_first_team = 0
    counter_second_team = 0

    # Loop through the contours and draw bounding boxes
    for cnt1 in contours_first_team:
        x, y, w, h = cv.boundingRect(cnt1)
        area1=cv.contourArea(cnt1)
        if 300<area1<1000:
             cv.rectangle(roi, (x, y), (x + w, y + h), (0, 255, 0), 2)
             counter_first_team += 1

    for cnt2 in contours_second_team:
        x, y, w, h = cv.boundingRect(cnt2)
        area2=cv.contourArea(cnt2)
        if 200<area2<500:
             cv.rectangle(roi, (x, y), (x + w, y + h), (0, 0, 255), 2)
             counter_second_team += 1

    # Display the player counts for both teams
    cv.putText(frame, f"Team 1: {counter_first_team}", (10, 30), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
    cv.putText(frame, f"Team 2: {counter_second_team}", (10, 60), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

    # Show the frame with bounding boxes
    cv.imshow('Frame', frame)

    # Exit the loop on pressing 'd'
    if cv.waitKey(20) & 0xFF == ord('d'):
        break

# Release the capture object and close the windows
capture.release()
cv.destroyAllWindows()

