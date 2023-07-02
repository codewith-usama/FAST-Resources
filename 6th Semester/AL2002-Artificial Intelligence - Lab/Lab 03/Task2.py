def car_camera_system(front_cam, left_cam, right_cam, rear_cam):
    """
    Function that takes inputs from car cameras and applies actions based on the detected objects.

    Args:
    front_cam (float): distance of object detected by front camera in meters
    left_cam (float): distance of object detected by left camera in meters
    right_cam (float): distance of object detected by right camera in meters
    rear_cam (float): distance of object detected by rear camera in meters

    Returns:
    None
    """
    if front_cam <= 8:
        # Apply brakes if object detected within 8 meters by front camera
        print("Object detected within 8 meters by front camera. Applying brakes...")
    if left_cam <= 2:
        # Move to right lane if object detected within 2 meters by left camera
        print("Object detected within 2 meters by left camera. Moving to right lane...")
    if right_cam <= 2:
        # Move to left lane if object detected within 2 meters by right camera
        print("Object detected within 2 meters by right camera. Moving to left lane...")
    if rear_cam <= 0.05:
        # Apply brakes if object detected within 5 cm by rear camera while parking
        print(
            "Object detected within 5 cm by rear camera. Applying brakes while parking...")


# Example usage of the function
car_camera_system(front_cam=6.5, left_cam=3.2, right_cam=1.5, rear_cam=0.03)
