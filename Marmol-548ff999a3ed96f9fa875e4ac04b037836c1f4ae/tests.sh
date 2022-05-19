TESTSPORO=25
TESTSVECTOR=19
TESTSTLISTA=15
TESTSABBPORO=23
TESTSAVLPORO=13
nombreBase="tad"
extension=".cpp"
zero="0"

echo "Autocorrector Cuadernillo 1 PED"
echo "1. Test TPoro"
echo "2. Test TVectorPoro"
echo "3. Test TListaPoro"
echo "4. Test TABBPoro"
echo "5. Test TAVLPoro"
echo "6. Todos"
echo 'Opcion: '
read Opcion
if (( $Opcion == 1 || $Opcion == 6 )); then
	
	echo "//////////////////////////////////////////////////////////////////"
	echo "///////////////////////Pruebas TPoro//////////////////////////////"
	cp src/tporo/*.cpp src/
	for (( i = 1; i <= $TESTSPORO; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tporo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
if (( $Opcion == 2 || $Opcion == 6 )); then

	echo "//////////////////////////////////////////////////////////////////"
	echo "//////////////////////Pruebas TVectorPoro/////////////////////////"
	cp src/tvectorporo/*.cpp src/
	for (( i = 1; i <= $TESTSVECTOR; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tvectorporo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
if (( $Opcion == 3 || $Opcion == 6 )); then
	echo "//////////////////////////////////////////////////////////////////"
	echo "///////////////////////Pruebas TListaPoro/////////////////////////"
	cp src/tlistaporo/*.cpp src/
	for (( i = 1; i <= $TESTSTLISTA; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tlistaporo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
if (( $Opcion == 4 || $Opcion == 6 )); then
	echo "//////////////////////////////////////////////////////////////////"
	echo "///////////////////////Pruebas TABBPoro///////////////////////////"
	cp src/tabbporo/*.cpp src/
	for (( i = 1; i <= $TESTSABBPORO; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tabbporo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
if (( $Opcion == 5 || $Opcion == 6 )); then
	echo "//////////////////////////////////////////////////////////////////"
	echo "///////////////////////Pruebas TAVLPoro///////////////////////////"
	cp src/tavlporo/*.cpp src/
	for (( i = 1; i <= $TESTSAVLPORO; i++ )); do
		
		if (($i >= 10)); then
			nombre=$nombreBase$i$extension 
		else
			nombre=$nombreBase$zero$i$extension 
		fi
		echo $nombre
		mv src/$nombre src/tad.cpp
		make > basura.txt
		./tad > $i.txt
		diff -b $i.txt salidas/tavlporo/$nombre.sal
		mv src/tad.cpp src/$nombre
		rm ./tad
		rm ./basura.txt
		rm $i.txt
		
	done
	rm src/*.cpp
fi
