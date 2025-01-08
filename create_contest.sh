#!/bin/bash

create_files(){
	local base_dir="$1"
	local contest_dir="$2"
	local end_char="$3"
	local template_file="$4"
	local template_name="$5"

	local full_path="$base_dir/$contest_dir"

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
	  echo "Created $full_path/$char.cpp using $template_name"
	done
	cp "$template_file" "$full_path/base.cpp"
	echo "Created $full_path/base.cpp using $template_name"
}

create_single_file() {
	local base_dir="$1"
	local contest_dir="$2"
	local exercise_name="$3"
	local template_file="$4"
	local template_name="$5"

	local full_path="$base_dir/$contest_dir"

	if [ -d "$full_path" ]; then
		echo "Error: Directory '$full_path' already exists."
        exit 1
    fi
  
	mkdir -p "$full_path"
	cp "$template_file" "$full_path/$exercise_name.cpp"
	echo "Created $full_path/$exercise_name.cpp using $template_name"
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --cf) # CodeForces
			echo "###############################"
			echo "###########CODEFORCES##########"
			echo "###############################"
			TEMPLATE_FILE="./templates/cf_base.cpp"
			TEMPLATE_NAME="cf_base.cpp"
			shift
			;;
        --atcoder) # AtCoder
			echo "###############################"
			echo "#############ATCODER###########"
			echo "###############################"
			TEMPLATE_FILE="./templates/atcoder_base.cpp"
			TEMPLATE_NAME="atcoder_base.cpp"
			shift
			;;
        --cses) # CSES
			echo "###############################"
			echo "#############CSES##############"
			echo "###############################"
            exercise_name="$4"
            TEMPLATE_FILE="./templates/cses_base.cpp"
            TEMPLATE_NAME="cses_base.cpp"
            create_single_file "$2" "$3" "$exercise_name" "$TEMPLATE_FILE" "$TEMPLATE_NAME"
            exit 0
            ;;
        --usaco) # USACO
			echo "###############################"
			echo "#############USACO#############"
			echo "###############################"
			exercise_name="$4"
			TEMPLATE_FILE="./templates/usaco_base.cpp"
			TEMPLATE_NAME="usaco_base.cpp"
			create_single_file "$2" "$3" "$exercise_name" "$TEMPLATE_FILE" "$TEMPLATE_NAME"
			exit 0
			;;
        -* | --*) # Error if there is not anything
            echo "Error: Unknown option '$1'"
            echo "Usage: $0 [--cf|--atcoder|--cses|--usaco] <base_dir> <contest_dir> <last_question_in_char (optional)> or <exercise_name>"
             exit 1
            ;;
        *)
            break # Stop parsing options
            ;;
    esac
done
if [ $# -lt 2 ] ; then
     echo "Usage: $0 [--cf|--atcoder] <base_dir> <contest_dir> <last_question_in_char (optional)>"
    exit 1
fi
base_dir="$1"
contest_dir="$2"
end_char="${3:-d}"

# Call create_files with the extracted template and params
create_files "$base_dir" "$contest_dir" "$end_char"


