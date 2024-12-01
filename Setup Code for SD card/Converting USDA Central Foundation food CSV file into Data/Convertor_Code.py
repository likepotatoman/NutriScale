import CSV

with open(r"C:\Users\dmlam\Downloads\FoodData_Central_foundation_food_csv_2024-10-31\foundation_food.csv", mode='r') as file:
    reader = csv.reader(file)
	foundation_food = []
    for row in reader:
        foundation_food.append([row[0],row[1]])
