str_ = input()
data = [str_[i:i+2] for i in range(0,len(str_),2)]

score = {"A" : 0,  "B" : 0}

for point in data:
    score[point[0]] += int(point[1])

if score["A"] > score["B"]:
    print("A")
else:
    print("B")