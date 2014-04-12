#!/bin/sh
#git@github.com:rootid/git_hooks.git
repo_name=${1}
user_name=${2}
[ "${user_name}" ] || user_name="rootid"
git remote add origin git@github.com:${user_name}/${repo_name}.git
