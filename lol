vim () {
    if [ -e "$1" ] || [ -z "$1" ]; then
        command vim ${1:+"$1"}
    else
        printf 'No such file or directory: %s\n' "$1" >&2
        return 1
    fi
}
