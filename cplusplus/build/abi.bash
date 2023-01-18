#!/usr/bin/env bash


args=("$@")
abi_not_parsed=("$(grep 'case ABI_*' ${args[0]})")
abi_methods=
for method in $abi_not_parsed
do
	if [[ "${method}" == "case" ]]
	then
		continue
	fi
	method_val="${method#"ABI_"}"
	method_val="${method_val%":"}"
	abi_methods+=("${method_val}")
done
for ((i = 1; i < ${#abi_methods[@]}; i++))
do
	#abi_methods[$i]="${abi_methods[$i],}"
	abi_methods[$i]="$(echo "${abi_methods[$i]}" | tr "[:upper:]" "[:lower:]")"
    echo "${abi_methods[$i]}"
done
abi_funcs_params=
for ((i = 1; i < ${#abi_methods[@]}; i++))
do
	pattern="${abi_methods[$i]}"
	pattern+="(=*"
	abi_funcs_params+=("$(grep "$pattern" token.cpp)")
done
for ((i = 1; i < ${#abi_funcs_params[@]}; i++))
do
    echo "${abi_funcs_params[$i]}"
done
types=("bool" "string" "uint8" "uint64" "uint256" "int8" "int64" "int256" "address" "void"
	"address[]" "int8[]" "int256[]" "uint256[]" "address[]" "string[]" "bool[]" "uint8[]" "int64[]" "uint64[]")
methods=
i=0
contract_abi="${args[0]/%".cpp"}.abi"
rm "${contract_abi}"
touch "${contract_abi}"
for abi_func in "${abi_funcs_params[@]}"
do
	echo "${abi_func}"
	j=0
	parsed_method=()
	prev_is_type=0
	for name in $abi_func
	do
		if [[ "${name}" == "{" ]]
		then
			continue
		fi
		#echo "${name}"
		#echo "${j}"
		#echo "${prev_is_type}"
		if (( j == 0 )) && [[ "${name}" == "static" ]]
		then
			continue
		fi
		if (( j == 0 )) && [[ " ${types[@]} " =~ " ${name} " ]]
		then
			parsed_method+=( "${name}" )
			parsed_method+=( "${abi_methods[$i]}" )
			j=$((j + 1))
			continue
		elif (( j == 0 ))
		then
			echo "ERROR_FUNCTION"
			exit 0
		fi
		if (( j == 1 ))
		then
			prefix="${abi_methods[$i]}("
			first_param_type="${name/#"$prefix"}"
			if [[ "${first_param_type}" == "" ]] || [[ "${first_param_type}" == ")" ]]
			then
				continue
			else
				parsed_method+=("${first_param_type}")
			fi
		fi
		if (( j > 1 ))
		then
			parsed_name=${name/#","}
			parsed_name=${parsed_name/%","}
			parsed_name=${parsed_name/%")"}
			x=$(($prev_is_type % 2))
			if ( [[ ! "${types[@]}" =~ "${parsed_name}" ]] && (( x == 1 )) ) || ( [[ "${types[@]}" =~ "${parsed_name}" ]] && (( x == 0 )) )
			then
				parsed_method+=( "${parsed_name}" )
			else
				echo "ERROR_PARAMS"
				exit 0
			fi
		fi
		prev_is_type=$(($prev_is_type + 1))
		j=$(($j + 1))
	done
	i=$(($i + 1))
	methods+=("${parsed_method}")
	k=0
	for param in "${parsed_method[@]}"
	do
	    echo "${param}" >> "${contract_abi}"
	done
	echo "" >> "${contract_abi}"
done
echo "${methods}"
