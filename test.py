def main():
    f = open('frases.txt', 'r')
    f2 = open('frasesclean.txt', 'w')
    lines = f.readlines()
    for line in lines:
        line = line.replace('- ', '')
        # print(line)
        f2.write(line)

if __name__ == '__main__':
    main()
