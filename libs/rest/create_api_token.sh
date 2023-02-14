#!/usr/bin/env bash

set -eu

description=$1
password=$2
salt=$(openssl rand -hex 8)
method=sha256
hash=$(echo -n $password| openssl sha256 -hmac "$salt")
expires=$(gdate +"%Y-%m-%dT%H:%M:%SZ" -d 'tomorrow') # token expires in 24 hrs

jq --null-input \
   --arg hash "$method\$$salt\$$hash" \
   --arg desc "$description" \
   --arg exp "$expires" \
   '[{ "hash" : $hash, "description" : $desc, "expires_at" : $exp }]'