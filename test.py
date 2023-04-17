ins_a = ["swap", "rotate", "swap", "reverse_rotate"]
ins_b = ["swap"]
result = ["","","","","","","","","",""]

def merge_instructions(i_a,i_b,res):
    i = 0
    j = 0
    k = 0
    while (i < len(i_a)) and (j < len(i_b)):
        if i_a[i] == i_b[j]:
            res[k] = i_a[i]
            j += 1
            i += 1
        elif (len(i_a) - i) > (len(i_b) - j):
            res[k] = i_a[i] + "_a"
            i += 1
        else:
            res[k] = i_b[j] + "_b"
            j += 1
        k += 1
    while i < len(i_a):
        res[k] = i_a[i] + "_a"
        i += 1
        k += 1
    while j < len(i_b):
        res[k] = i_b[j] + "_b"
        k += 1
        k += 1
    print(res)

merge_instructions(ins_a, ins_b, result)