library = {
    "s1": ["Ds", "os", "uhv"],
    "s2": ["Ds", "os"],
    "s3": ["ds"],
    "s4": [],
}

avg = 0
List = []
length = len(library)

for i in library.values():
    print(i)
    List.append(i)
print(List)

total = 0
for i in List:
    total += len(i)

print("Total Books borrowed", total)
print("Average number of books:", total / length)

count = {}
for sub in library.values():
    for i in sub:
        if i in count:
            count[i] += 1
        else:
            count[i] = 1

for i in count:
    if count[i] > 1:
        print("Repeated Book is:", i, " And repeatation number is:", count[i])

bcount = 0
for stu, book in library.items():
    if len(book) == 0:
        bcount += 1
        print(bcount, " student hasn't borrowed any book yet!!", stu)

hbook = {}
for book in library.values():
    for i in book:
        if i in hbook:
            hbook[i] += 1
        else:
            hbook[i] = 1

max_count = -1
for book in hbook:
    if hbook[book] > max_count:
        max_count = hbook[book]
        mostboro = book

min_count = float('inf')
for book in hbook:
    if hbook[book] < min_count:
        min_count = hbook[book]
        leastboro = book

print("Most borrowed book:", mostboro, ":", max_count, "times")
print("Least borrowed book:", leastboro, ":", min_count, "times")
