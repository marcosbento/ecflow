#!/usr/bin/env bash

# As per https://confluence.ecmwf.int/display/ECFLOW/Open+ssl

# Generate private key

openssl genrsa -out server.key 2048
#openssl genrsa -des3 -out server.key 1024
chmod 400 server.key # Ensure that it is protected

# Generate Certificate Signing Request (CSR)
openssl req -new -key server.key -out server.csr

# Generate (Self-Signed) Certificate (CRT)
openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt

# Alternative suggestion could be found at: https://serverfault.com/questions/224122/what-is-crt-and-key-files-and-how-to-generate-them
#
# - openssl genrsa 2048 > host.key
# - chmod 400 host.key
# - openssl req -new -x509 -nodes -sha256 -days 365 -key host.key -out host.cert
#
