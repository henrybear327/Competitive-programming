for ((i = 1; ; i++)); do
        echo $i
        python3 ./gen.py > inp
        diff -w <(./a.out < inp) <(./ans < inp) || break
done
