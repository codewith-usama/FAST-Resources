def average_temp(sensors_data):
    """Calculate the average temperature in Fahrenheit using the data received from the sensors."""
    # Convert the temperature data in centigrade to Fahrenheit
    f_temps = [((9/5) * c_temp + 32) for c_temp in sensors_data]

    # Calculate the average temperature in Fahrenheit
    avg_temp = sum(f_temps) / len(f_temps)

    return avg_temp


# Example usage
# Data received from the sensors in centigrade
sensors_data = [20, 22, 19, 18, 25, 24, 23, 21, 20]
avg_temp = average_temp(sensors_data)
print("Average temperature in Fahrenheit: {:.2f}".format(avg_temp))
