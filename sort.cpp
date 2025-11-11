emp_sal = []
n = int(input("enter the no of salary to sort:"))

for i in range(n):
    sal = float(input("enter the salary:"))
    emp_sal.append(sal)

def selection(A,n):
    for i in range(0,n-1):
        min = i
        for j in range(i+1,n):
            if A[min] > A[j]:
                min = j
        A[i],A[min] = A[min],A[i]
    return A
print(f"the sorted list is " , selection(emp_sal,n))

def bubble(A,n):
    for i in range(n-1):
        for j in range(n-i-1):
            if A[j] > A[j+1]:        # compare adjacent elements
                A[j], A[j+1] = A[j+1], A[j]  # swap
    return A

print("Sorted Salaries:", bubble(emp_sal, n))

