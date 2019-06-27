cat /etc/passwd | grep -v ^# | awk '0 == NR%2' | cut -d ':' -f 1 | rev | sort -r | sed -n "$FT_LINE1, $FT_LINE2"p | tr '\n' ' ' | sed 's/ /, /g' | sed 's/..$/./' | tr -d '\n'
