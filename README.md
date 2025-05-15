# atcoder-nix

## 開発用シェルの起動方法

```sh
nix develop -c "$SHELL"
```

## プログラムのビルド方法

```sh
./build [MODE] C++ファイル
```

`MODE` には `gcc`、`clang`、`san` のいずれかを指定する。

- `gcc` - gcc でコンパイルする
- `clang` - clang でコンパイルする
- `san` - Address Sanitizer、Undefined Behavior Sanitizer を有効化して clang でコンパイルする

`MODE` を省略すると `clang` が指定されたものとみなされる。

`a.out` が出力されるので `./a.out` で実行する。
