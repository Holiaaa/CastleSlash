import os

file = []

for element in os.listdir():
    line = element.split(".")
    if line[1] == "cpp":
        file.append(element)

print(file)

file_string = ""
for files in file:
    file_string = file_string + files + " "

print("--------------------------------------------------")
print("Build...")
print("--------------------------------------------------")
print("g++ " + file_string + " -o main.exe")
os.system("g++ " + file_string + " -o main.exe")
print("\n--------------------------------------------------")
print("Testing...")
print("--------------------------------------------------\n")
os.system("main.exe")