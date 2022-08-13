build() {
    python setup.py build_ext --inplace
}

install() {
    python -m pip install -e .
}

case $1 in
    "build") build $@ ;;
    "install") install $@ ;;
esac
