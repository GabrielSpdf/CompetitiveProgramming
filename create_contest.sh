#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: $0 <base_dir> <contest_name> <last_question_in_char (optional)>"
    echo "For example: $0 c1 Contest1 f base.cpp"
    exit 1
fi

base_dir="$1"
contest_dir="$2"
end_char="${3:-d}" # 4 questions as default   
template_file="./template/base.cpp"

full_path="$base_dir/$contest_dir"

if [ -d "$full_path" ]; then
    echo "Error: Directory '$full_path' already exists."
    exit 1
fi

mkdir -p "$full_path"

for char in a b c d e f g h i j k l m n o p; do
  if [[ "$char" > "$end_char" ]]; then
    break
  fi
  cp "$template_file" "$full_path/$char.cpp"
  echo "Created $full_path/$char.cpp"
done
cp "$template_file" "$full_path/base.cpp"
echo "Created $full_path/base.cpp"
