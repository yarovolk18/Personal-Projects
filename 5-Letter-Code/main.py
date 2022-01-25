import csv


# READING IN FROM TXT
def read_in():
    words = []
    f = open('data_3.txt', 'r')

    # for line in f:
    lines = f.read().splitlines()
    for line in lines:
        words.extend(line.split())

    f.close()
    return words


# CUTTER
def operations(wordf2):
    if len(wordf2) == 5 and wordf2.isalpha():
        return wordf2
    elif len(wordf2) > 5 and wordf2.isalpha():
        wordf2 = wordf2[0:5]
        return wordf2
    elif len(wordf2) > 5 and not wordf2.isalpha():
        foo = []
        for j in range(len(wordf2)):
            foo.append(wordf2[j])
        for j in range(len(foo)):
            if not foo[j].isalpha():
                foo.pop(j)
                foo.insert(j, " ")
        foo2 = "".join(foo).split()
        foo3 = []
        for i in range(len(foo2)):
            if operations(foo2[i]) is not None:
                foo3.append(operations(foo2[i]))
        return foo3
    else:
        return None


# EXTRACTING ALL 5-LETTER WORDS
def extract(words):
    five_letter = []
    for i in range(len(words)):
        place_hold = operations(words[i])
        if place_hold is not None:
            if type(place_hold) == str:
                five_letter.append(place_hold)
            else:
                for j in range(len(place_hold)):
                    five_letter.append(place_hold[j])

    return five_letter


# WRITING TO CSV
def write_in(words):
    with open('output.csv', 'w', newline='') as f:
        writer = csv.writer(f)
        for i in range(len(words)):
            writer.writerow(words[i])
    f.close()


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    words = read_in()
    words = extract(words)
    write_in(words)
