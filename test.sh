#!/bin/bash

# files for testing
file1="testing_files/file_for_cat_0.txt"
file2="testing_files/file_for_cat_1.txt"

# flags
flags=("" "-n" "-b" "-s" "-t" "-v" "--number-nonblank" "-E" "--number"
  "--squeeze-blank" "-T")

# is_printed - output is success
# 0 == print output
# 1 == don't
is_printed=0

# commands
cmd1="cat"
cmd2="./s21_cat"

# init counts
successful_count=0
failed_count=0

run_and_compare() {
  if [ $is_printed -eq 0 ]; then
    echo "Running: $cmd1 $@ $file1 $file2"
  fi
  $cmd1 $@ "$file1" "$file2" > cmd1_output.txt

  if [ $is_printed -eq 0 ]; then
    echo "Running: $cmd2 $@ $file1 $file2"
  fi
  $cmd2 $@ "$file1" "$file2" > cmd2_output.txt

  if diff cmd1_output.txt cmd2_output.txt > /dev/null; then
    if [ $is_printed -eq 0 ]; then
      echo -e "\033[0;32mSuccess\033[0m"
      echo ""
    fi
    ((successful_count++))
  else
    echo -e "\033[0;31mFailed:\033[0m $cmd2 $@ $file1 $file2"
    ((failed_count++))
    echo ""
  fi
}

for flag1 in "${flags[@]}"; do
  run_and_compare "$flag1"
done

for flag1 in "${flags[@]}"; do
  for flag2 in "${flags[@]}"; do
    if [ "$flag1" != "$flag2" ]; then
      run_and_compare "$flag1" "$flag2"
    fi
  done
done

for flag1 in "${flags[@]}"; do
  for flag2 in "${flags[@]}"; do
    for flag3 in "${flags[@]}"; do
      if [ "$flag1" != "$flag2" ] && [ "$flag1" != "$flag3" ] &&
        [ "$flag2" != "$flag3" ]; then
        run_and_compare "$flag1" "$flag2" "$flag3"
      fi
    done
  done
done

echo -e "\033[1;34mTotal successful runs: $successful_count\033[0m"
echo -e "\033[1;34mTotal failed runs: $failed_count\033[0m"

rm -f cmd1_output.txt cmd2_output.txt

