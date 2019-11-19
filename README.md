# ft_ssl

A reproduction of openssl hashing algorithms
## Usage

```bash
$> make
$> ./ft_ssl command [command opts] [command args]
```
Only tested on OS X.

#### Available hashing algorithms:

- `SHA1`
- `SHA256`
- `SHA224`
- `SHA512`
- `MD5`

#### Avaliable flags:

- `-p` echo STDIN to STDOUT and append the checksum to STDOUT
- `-q` quiet mode
- `-r` reverse the format of the output
- `-s` print the sum of the given string
