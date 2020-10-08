# security-focused general purpose memory allocator #

This is a security-focused general purpose memory allocator providing the
malloc API along with various extensions. It provides substantial hardening
against heap corruption vulnerabilities. The security-focused design also
leads to much less metadata overhead and memory waste from fragmentation than
a more traditional allocator design. It aims to provide decent overall
performance with a focus on long-term performance and memory usage rather than
allocator micro-benchmarks. It offers scalability via a configurable number of
entirely independently arenas, with the internal locking within arenas further
divided up per size class.

It can be added as a preloaded library using /etc/ld.so.preload.

Ships two files:

* [1] /usr/lib/libhardened_malloc.so/libhardened_malloc.so
* [2] /usr/lib/libhardened_malloc.so/libhardened_malloc_kicksecure.so

[1] Is was compiled with Hardened Malloc compilation parameters.

[2] Uses a modified configuration that aims to be suitable to be enabled by
default in Whonix and Kicksecure. It is a lightweight fork of Hardened
Malloc by Kicksecure developers with no other changes than compilation
parameters.
## How to install `hardened_malloc` using apt-get ##

1\. Download Whonix's Signing Key.

```
wget https://www.whonix.org/patrick.asc
```

Users can [check Whonix Signing Key](https://www.whonix.org/wiki/Whonix_Signing_Key) for better security.

2\. Add Whonix's signing key.

```
sudo apt-key --keyring /etc/apt/trusted.gpg.d/whonix.gpg add ~/patrick.asc
```

3\. Add Whonix's APT repository.

```
echo "deb https://deb.whonix.org buster main contrib non-free" | sudo tee /etc/apt/sources.list.d/whonix.list
```

4\. Update your package lists.

```
sudo apt-get update
```

5\. Install `hardened_malloc`.

```
sudo apt-get install hardened_malloc
```

## How to Build deb Package from Source Code ##

Can be build using standard Debian package build tools such as:

```
dpkg-buildpackage -b
```

See instructions. (Replace `generic-package` with the actual name of this package `hardened_malloc`.)

* **A)** [easy](https://www.whonix.org/wiki/Dev/Build_Documentation/generic-package/easy), _OR_
* **B)** [including verifying software signatures](https://www.whonix.org/wiki/Dev/Build_Documentation/generic-package)

## Contact ##

* [Free Forum Support](https://forums.whonix.org)
* [Professional Support](https://www.whonix.org/wiki/Professional_Support)

## Donate ##

`hardened_malloc` requires [donations](https://www.whonix.org/wiki/Donate) to stay alive!