### Arithmetic in python
```python
>>> x=28  #int
>>> y=28.0 #double
>>> float(x) #typecast to float
28.0
>>> z=3.14 #float
>>> int(z) #typecast to int
3
>>> x=1.732 #float
>>> 1.732+0j
(1.732+0j)
>>> complex(1.732) #typecast to complex no
(1.732+0j)

>>> a=2+3i #invalid complex no
  File "<stdin>", line 1
    a=2+3i
         ^
SyntaxError: invalid syntax
>>> a=2+3j
>>> type(a) #type of a
<class 'complex'>
>>> a=complex(input()) #input complex no
3+4j
>>> type(a) #type of a
<class 'complex'>
>>> a.real #real part of a
3.0
>>> a.imag #imaginary part of a
4.0
```
_Sample program to input a complex no and print its real and imaginary part_

```python
import cmath
a=complex(input())
print(abs(complex(a.real,a.imag)))
print(cmath.phase(complex(a.real,a.imag)))
```

_input_
```
1+2j
```
_output_
```
 2.23606797749979
 1.1071487177940904
```
### break Statement

```python
for i in range(10):
	print("i=",i)
	for j in range(10):
		print(j)
		if(j==5):
			break; #breaks only immediate loop to this break not outer for loop
	print("outter for at ",j)
print("outta loop")
```

Note: goto statement does not exist in python

### Sets

 A set contains an unordered collection of unique and immutable objects.The set data type is, as the name implies,
 a Python implementation of the sets as they are known from mathematics.This explains, why sets unlike lists or tuples can't have multiple occurrences of the same element.

an empty set can be defined as

```python
variable = set() # iniialize a set
```

_taking set input from user on consnole 1 2 2 3 3 4 5 6 7 7 7

```python
s = set(map(int, input().split()))
```
If we want to add a single element to an existing set, we can use the `.add()` operation.
It adds the element to the set and returns 'None'.

_Example1_

```python
>> myset.add('c')
>> myset
{'a', 'c', 'b'}
>> myset.add('a') # As 'a' already exists in the set, nothing happens
>> myset.add((5, 4))
>> myset
{'a', 'c', 'b', (5, 4)}
```

_Example2_

```python
>>> s = set('ackerRank')
>>> s.add('H')
>>> print s
set(['a', 'c', 'e', 'H', 'k', 'n', 'r', 'R'])
>>> print s.add('HackerRank')
None
>>> print s
set(['a', 'c', 'e', 'HackerRank', 'H', 'k', 'n', 'r', 'R'])
```
_.remove(x)_

This operation removes element from the set.
If element does not exist, it raises a KeyError.
The .remove(x) operation returns None.

_Example_

```python
>>> s = set([1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> s.remove(5)
>>> print s
set([1, 2, 3, 4, 6, 7, 8, 9])
>>> print s.remove(4)
None
>>> print s
set([1, 2, 3, 6, 7, 8, 9])
>>> s.remove(0)
KeyError: 0
```

_.discard(x)_

This operation also removes element from the set.
If element does not exist, it does not raise a KeyError.
The `.discard(x)` operation returns `None`.

Example

```python
>>> s = set([1, 2, 3, 4, 5, 6, 7, 8, 9])
>>> s.discard(5)
>>> print s
set([1, 2, 3, 4, 6, 7, 8, 9])
>>> print s.discard(4)
None
>>> print s
set([1, 2, 3, 6, 7, 8, 9])
>>> s.discard(0)
>>> print s
set([1, 2, 3, 6, 7, 8, 9])
```

_.pop()_

This operation removes and return an arbitrary element from the set. If there are no elements to remove, it raises a KeyError.

Example

```python
>>> s = set([1])
>>> print s.pop()
1
>>> print s
set([])
>>> print s.pop()
KeyError: pop from an empty set
```
_Common SET operations  union(), intersection() and difference() functions._

```python
>> a = {2, 4, 5, 9}
>> b = {2, 4, 11, 12}
>> a.union(b) # Values which exist in a or b
{2, 4, 5, 9, 11, 12}
>> a.intersection(b) # Values which exist in a and b
{2, 4}
>> a.difference(b) # Values which exist in a but not in b
{9, 5}

>>> s = set("Hacker")
>>> print s.union("Rank")
set(['a', 'R', 'c', 'r', 'e', 'H', 'k', 'n'])

>>> print s.union(set(['R', 'a', 'n', 'k']))
set(['a', 'R', 'c', 'r', 'e', 'H', 'k', 'n'])

>>> print s.union(['R', 'a', 'n', 'k'])
set(['a', 'R', 'c', 'r', 'e', 'H', 'k', 'n'])

>>> print s.union(enumerate(['R', 'a', 'n', 'k']))
set(['a', 'c', 'r', 'e', (1, 'a'), (2, 'n'), 'H', 'k', (3, 'k'), (0, 'R')])

>>> print s.union({"Rank":1})
set(['a', 'c', 'r', 'e', 'H', 'k', 'Rank'])

>>> s | set("Rank")
set(['a', 'R', 'c', 'r', 'e', 'H', 'k', 'n'])
```

The union() and intersection() functions are symmetric methods:

```python
>> a.union(b) == b.union(a)
True
>> a.intersection(b) == b.intersection(a)
True
>> a.difference(b) == b.difference(a)
False
```




#### Lists in python

Consider a list `list = []`. You can perform the following commands:

1. insert i e: Insert integer e at position i.
2. print: Print the list.
3. remove e: Delete the first occurrence of integer e.
4. append e: Insert integer e at the end of the list.
5. sort: Sort the list.
6. pop: Pop the last element from the list.
7. reverse: Reverse the list.

When we talk about storing multiple values in a container-like data structure,
the first thing that comes to mind is a list.

You can initialize a list as: `arr = list()`
or `arr = []` or with a few elements as: `arr = [1,2,3]`

Elements can be accessed easily similar to most programming languages:

```python
print arr[0]
result is 1
print arr[0] + arr[1] + arr[2]
result is 6
```

Lists in Python are very versatile. You can add almost anything in a Python list.
In Python, you can create a list of any objects: strings, integers, or even lists. You can even add multiple types in a single list!

Let's look at some of the methods you can use on list.

1. _append(x)_: Adds a single element x to the end of a list.

```python
arr.append(9)
print arr #[1, 2, 3, 9]
```
2. _extend(L)_: Merges another list L to the end.

```python
arr.extend([10,11])
print arr #[1, 2, 3, 9, 10, 11]
```

3. _insert(i,x)_: Inserts element x at position i.

```python
arr.insert(3,7)
print arr #[1, 2, 3, 7, 9, 10, 11]
```
4. _remove(x)_: Removes the first occurrence of element x.

```python
arr.remove(10)
print(arr) #[1, 2, 3, 7, 9, 11]
```

5. _pop()_: Removes the last element of a list. If an argument is passed, that index item is popped out.

```python
temp = arr.pop()
print temp # 11
```
6. _index(x)_: Returns the first index of a value in the list. Throws an error if it's not found.
```python
temp = arr.index(3)
print temp # 2
```

7. _count(x)_: Counts the number of occurrences of an element x.
```python
temp = arr.count(1)
print temp # 1
```
8. _sort()_: Sorts the list.

```python
arr.sort()
print arr # [1, 2, 3, 7, 9]
```
9. _reverse()_ : Reverses the list.

```python
arr.reverse()
print arr # [9, 7, 3, 2, 1]
```

10. _copy_ : Return a shallow copy of the list. Equivalent to a[:].

```py
arr.copy()
```

```py
fruits = ['orange', 'apple', 'pear', 'banana', 'kiwi', 'apple', 'banana']
>>> fruits.count('apple')
2
>>> fruits.count('tangerine')
0
>>> fruits.index('banana')
3
>>> fruits.index('banana', 4)  # Find next banana starting at position 4
6
>>> fruits.reverse()
>>> fruits
['banana', 'apple', 'kiwi', 'banana', 'pear', 'apple', 'orange']
>>> fruits.append('grape')
>>> fruits
['banana', 'apple', 'kiwi', 'banana', 'pear', 'apple', 'orange', 'grape']
>>> fruits.sort()
>>> fruits
['apple', 'apple', 'banana', 'banana', 'grape', 'kiwi', 'orange', 'pear']
>>> fruits.pop()
'pear'
```


11. Remove duplicates from a list by turning lists to sets

```python
>>>l=[1,2,2,3,3,4,4,4,54,5,56,23,2]
>>>l=list(set(l))
>>>l
   (1,2,3,4,5,23,54,56)

 append(...)
 |      L.append(object) -- append object to end
 |
 |  count(...)
 |      L.count(value) -> integer -- return number of occurrences of value
 |
 |  extend(...)
 |      L.extend(iterable) -- extend list by appending elements from the iterable
 |
 |  index(...)
 |      L.index(value, [start, [stop]]) -> integer -- return first index of value.
 |      Raises ValueError if the value is not present.
 |
 |  insert(...)
 |      L.insert(index, object) -- insert object before index

#list to tuple
l=[34, 35, 54, 46, 4343, 2]
t=tuple(l)

#quick conversion of str list to int list
l=raw_input().split()
>>>34 35 54 46 4343 2
['34', '35', '54', '46', '4343', '2']

1.for x in range(len(l)):
	l[x]=int(l[x])
>>>[34, 35, 54, 46, 4343, 2]

2.

4.list=[int(x) for x in l]
>>>[34, 35, 54, 46, 4343, 2]
```

#### Nested lists in python
```python
nested_list = [['blue', 'green'], ['red', 'black'], ['blue', 'white']]
print len(nested_list)
# prints 3
print nested_list[1]
# prints ['red', 'black']
print nested_list[1][0]
# prints red
```

### List Comprehensions

Lists compressions are used for one line code
syntax: [expr for val in collection]
	[expr for val in collection if<condition>]
we can also have more than one if clause
	[expr for val in collection if<condition 1> and <condition 2>]
	[expr for val in collection1 and val2 in collection 2]

e.g 	>>> squares=[i**2 for i in range(1,10)]
	>>> print squares
	[1, 4, 9, 16, 25, 36, 49, 64, 81]

Note: proved by Gauss
p_remainders = [x**2%p for x in range(p)]
len(p_remainders) = (p+1)/2


#### For loop without list comprehensions

```python
list=[("RJ",25),("MJ",28),("RDX",32),("AKA",54),("Danny",324),("VK",121)]

>>> for(name,num) in list:
	print name+" "+str(num)
```
_Output_
```
RJ 25
MJ 28
RDX 32
AKA 54
Danny 324
VK 121
```

#### for loop with list comprehensions

```python
print[names for (names,num) in list]
['RJ', 'MJ', 'RDX', 'AKA', 'Danny', 'VK']
>>> print[num for (names,num) in list if num%2==0]
[28, 32, 54, 324]
>>>print[names for (names,num) in list if num>40]
['AKA', 'Danny', 'VK']

#Cartesian Product using List Comprehensions
>>>A=[1,3,5,7,9]
>>> B=[2,4,6,8]
>>> Cartesian_Product=[(a,b)for a in A for b in B]
>>> print Cartesian_Product
[(1, 2), (1, 4), (1, 6), (1, 8), (3, 2), (3, 4), (3, 6), (3, 8), (5, 2), (5, 4), (5, 6), (5, 8), (7, 2), (7, 4), (7, 6), (7, 8), (9, 2), (9, 4), (9, 6), (9, 8)]
```

#### break statement

```python
for i in range(100):
	print("i=",i)
 	for j in range(100):
		print(j)
 		if(j==25):
			break; #breaks only immediate loop
 	print("outter for at ",j)

print("loop ended")
```

### Dictionary in python

Dictionaries are mutable, which means they can be changed.
The values that the keys point to can be any Python value.

_iterating keys in a dictionary_

```python
food_dict = {"ham" : "yes", "egg" : "yes", "pizza" : "yes","olive": "no" }

print "food_dict=",
print food_dict

print"\nkeys: ",
for food_keys in food_dict.keys():
	print food_keys,
```
_iterating values from a dictionary_

```python
print "\nvalues=",
for food_values in food_dict.values():
	print food_values,
```

_iterating key value pair from dictionary_

```python
for food_keys,food_values in food_dict.items():
	print str(food_keys) + ": " + str(food_values)
```
#### changing value of a key in a dictionary

_dictionares are mutable_

```python
resp='y'
while resp=="Y" or resp=='y':
	print "\ndictionary=",
	print food_dict
	resp=raw_input("add/change key-value of dictionary Y/N ")
	if resp =="y" or resp=='Y':
		key = raw_input("enter key to make changes:")
		value=raw_input("enter value for "+ str(key) +":")
		food_dict[key]=value
		print"length of food_dict=",len(food_dict)
print "out of dictionary"
```

#adding key-value pair in a dictionary

_without dictionary_

```python
string = input()
#aabcbdgadeff
list=[]
for i in range(len(string)):
	count=0
	if(string[i] not in list):
		for j in range(len(string)):
			if(string[i]==string[j]):
				count+=1;
		print("string--->",string[i]," ",count)
		list.append(string[i])
```

_Combinig two lists two dictionary_

```python
keys=[]
values=[]
for food_keys in food_dict.keys():
	keys.append(food_keys)
	values.append(food_dict[food_keys])
print "keys=",
print keys
print "values=",
print values
new_dict=dict(zip(keys,values))
print "new_dict=",
print new_dict
```

_deleting element from a dictionary_

```
key = raw_input("enter key to delete:")
if key in new_dict.keys():
	del(new_dict[key])
	print "key-value pair removed"
else:
	print "invaid key entered"
print "new_dict=",new_dict
```

_string frequency in dict_

```python
freq={}
string=raw_input("enter a string")
for i in string:
	freq[i]=0
for i in string:
	freq[i]+=1
print freq
```
_output_

```
mgm@lab3-5:~/Desktop$ python dict.py
food_dict= {'olive': 'no', 'egg': 'yes', 'ham': 'yes', 'pizza': 'yes'}

keys:  olive egg ham pizza
values= no yes yes yes
```

_key value pair in ditionary_

```python
olive: no
egg: yes
ham: yes
pizza: yes
```

#Note:Dictionaries Are Mutable

```python
dictionary= {'olive': 'no', 'egg': 'yes', 'ham': 'yes', 'pizza': 'yes'}
add/change key-value of dictionary Y/N y
enter key to make changes:egg
enter value for egg:no
length of food_dict= 4

dictionary= {'olive': 'no', 'egg': 'no', 'ham': 'yes', 'pizza': 'yes'}
add/change key-value of dictionary Y/N N
out of dictionary
```
_Combinig two lists two dictionary_

```python
keys= ['olive', 'egg', 'ham', 'pizza']
values= ['no', 'no', 'yes', 'yes']
new_dict= {'olive': 'no', 'egg': 'no', 'ham': 'yes', 'pizza': 'yes'}
************deleting element from a dictionary*************
enter key to delete:olive
key-value pair removed
new_dict= {'egg': 'no', 'ham': 'yes', 'pizza': 'yes'}
*****************string frequency in dict*******************
enter a string czechoslovakia
{'a': 2, ' ': 1, 'c': 2, 'e': 1, 'i': 1, 'h': 1, 'k': 1, 'l': 1, 'o': 2, 's': 1, 'v': 1, 'z': 1}
mgm@lab3-5:~/Desktop$
```


### Tuples in python

In Python, tuple is immutable. You cannot change elements of a tuple once it is assigned.

There are only 2 tuple methods that tuple objects can call:
1. count
2. index

The page contains theses 2 tuple methods. Also the page includes built-in functions that can take tuple as a parameter and perform some task.
For example, len(tuple) returns the length of a tuple (iterable).

1.We can access a range of items in a tuple by using the slicing operator - colon ":"

```python
>>>my_tuple = ('p','y','t','h','o','n')
>>> my_tuple[2:5]
('t', 'h', 'o')
2.Python allows negative indexing for its sequences.
The index of -1 refers to the last item,
 -2 to the second last item and so on.

>> my_tuple[:-3]
('p', 'y', 't')
>>> my_tuple[3:-3]
()
>>> my_tuple[1:-3]
('y', 't')
```

Python Tuple count() ->	returns occurrences of element in a tuple

```python
>>> t=('c','z','e','c','h','o','s','l','o','v','a','k','i','a')
>>> t.count('o')
2
>>> t.count(o)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'o' is not defined

#Tuple can only allow adding tuple to it. The best way to do it is:

mytuple =(u'2',)
mytuple +=(new.id,)
e.g
>>> mytuple = (u'2',)
>>> mytuple += ('example text',)
>>> print mytuple
(u'2','example text')

Python Tuple index() ->	returns smallest index of element in tuple
(['hello', 'world'], 121, 'python', {'python': 'Guido Van Rossum', 'C': 'Dennis Ritchie', 'java': 'james Gosling'}, 1990, 'Hello World')

>>> t.index(121)
>>> t.index('python')
>>> t.index('hello world')
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: tuple.index(x): x not in tuple
>>> t.index('Hello World')
```

`any()`: Checks if any Element of an Iterable is True

`all()`: returns true when all elements in iterable is true

`ascii()`: 	Returns String Containing Printable Representation

`bool()`: Coverts a Value to Boolean

`enumerate()`: 	Returns an Enumerate Object

`filter()`: constructs iterator from elements which are true

`iter()`: returns iterator for an o3bject

`len()`: Returns Length of an Object

>>>len(my_tuple)

`max():`: returns largest element

`min()`: 	returns smallest element

`map()`: 	Applies Function and Returns a List

`reversed()`: 	returns reversed iterator of a sequence

`slice()`: 	creates a slice object specified by range()

`sorted()`: 	returns sorted list from a given iterable

`sum()`: 	Add items of an Iterable

`tuple()`: Function 	Creates a Tuple

`zip()`: 	Returns an Iterator of Tup

### String Methods in python

Python has built-in string validation methods for basic data.
It can check if a string is composed of alphabetical characters,
 alphanumeric characters, digits, etc.

`str.isalnum()` : This method checks if all the characters of a string are alphanumeric (a-z, A-Z and 0-9).

```python
>>> print 'ab123'.isalnum()
True
>>> print 'ab123#'.isalnum()
False
```
`str.isalpha()` : This method checks if all the characters of a string are alphabetical (a-z and A-Z).

```python
>>> print 'abcD'.isalpha()
True
>>> print 'abcd1'.isalpha()
False
```

`str.isdigit()` : This method checks if all the characters of a string are digits (0-9).

```python
>>> print '1234'.isdigit()
True
>>> print '123edsd'.isdigit()
False
```

`str.islower()` : This method checks if all the characters of a string are lowercase characters (a-z).

```python
>>> print 'abcd123#'.islower()
True
>>> print 'Abcd123#'.islower()
False
```

`str.isupper()` : This method checks if all the characters of a string are uppercase characters (A-Z).

```python
>>> print 'ABCD123#'.isupper()
True
>>> print 'Abcd123#'.isupper()
False
```

`string.swapcase()`: converts lowercase to upper and vice versa

```python
>>> string="CZechOSloVAkia"
>>> string.swapcase()
'czECHosLOvaKIA'
```
`string.capitalize()` : Converts first character to Capital Letter

```python
>>> string.capitalize()
'Czechoslovakia'
```

_String to ascii and Vice Versa_
```python
>>> ord('a')
97
>>> chr(97)
'a'
>>> chr(ord('a') + 3)
'd'
>>>
```

`Python String center()`: Pads string with specified character

`Python String casefold()` : converts to casefolded strings
`String count()` :returns occurrences of substring in string
`String endswith()` : Checks if String Ends with the Specified Suffix
`String expandtabs()` : Replaces Tab character With Spaces

`String encode()` : returns encoded string of given string` String find`() :Returns the Highest Index of Substring

`String format()` : formats string into nicer output

`String index()` : Returns Index of Substring

`String isalnum()` :Checks Alphanumeric Character

`String isalpha()` :Checks if All Characters are Alphabets

`String isdecimal()` : Checks Decimal Characters

`String isdigit()` : Checks Digit Characters

`String isidentifier()` : Checks for Valid Identifier

`String islower()` : Checks if all Alphabets in a String are Lowercase

`String isnumeric()` : Checks Numeric Characters

`String isprintable()` : Checks Printable Character

`String isspace()` : Checks Whitespace Characters

`String istitle()` : Checks for Titlecased String

`String isupper()` : returns if all characters are uppercase characters

`String join()` : Returns a Concatenated String

`String ljust()` : returns left-justified string of given width

`String rjust()` : returns right-justified string of given width`y String lower() : returns lowercased string

`String upper()` : returns uppercased string

`String swapcase()` : swap uppercase characters to lowercase; vice versa

`String lstrip()` : Removes Leading Characters

`String rstrip()` : Removes Trailing Characters

`String strip()` : Removes Both Leading and Trailing Characters

`String partition()` : Returns a Tuple

`String maketrans()` : returns a translation table

`String rpartition()` : Returns a Tuple

`String translate()` : returns mapped charactered string

`String replace()` : Replaces Substring Inside

`String rfind()` : Returns the Highest Index of Substring

`String rindex()` : Returns Highest Index of Substring

`String split()` : Splits String from Left

`String rsplit()` : Splits String From Right

`String splitlines()` : Splits String at Line Boundaries

`String startswith()` : Checks if String Starts with the Specified String

`String title()` : Returns a Title Cased String

`String zfill()` : Returns a Co`of The String Padded With Zeros

`String format_map()` : Formats the String Using Dictionary

`any()` : Checks if any Element of an Iterable is True

`all()` : returns true when all elements in iterable is true

`ascii()` : Returns String Containing Printable Representation

`bool()`: Coverts a Value to Boolean

`bytearray()` : returns array of given byte size

`bytes()` : returns immutable bytes object

`compile()` : Returns a Python code object

`complex()` : Creates a Complex Number

`enumerate()` : Returns an Enumerate Object

`filter()` : constructs iterator from elements which are true

`float()` : returns floating point number from number, string

`input()` : reads and returns a line of string

`int()` : returns integer from a number or string

`iter()` : returns iterator for an object

`len()` : Returns Length of an Object

`max()` : returns largest element

`min()` : returns smallest element

`map()` : Applies Function and Returns a List

`ord()` : returns Unicode code point for Unicode character

`reversed()` : returns reversed iterator of a sequence

`slice()` : creates a slice object
`specified by range()`

`sorted()` : returns sorted list from a given iterable

`sum()` : Add items of an Iterable

`zip()` : Returns an Iterator of Tuples
Also check

Built-in Functions
List Methods
Dictionary Methods
String Methods
Set Methods
Tuple Methods

#### formatting Strings in python

```
>>>'this is our string {}'.format('in python')
'this is our string in python '
>>> '{3} {2} {1}'.format(' string3' , 'string2' ,'string1')
    'string1 string2 string3'
>>> 'We are learning {language}{version}'.format(language='python',version='3')
    'We are learning python 3'
>>> language=('Python','3')
>>> 'we are learning {0[0]}{0[1]}'.format(language)
    'we are learning Python 3'


string.split(): this method splits the input string into parts
```

 e.g In Python, a string can be split on a delimiter.

Example:

```python
>>> a = "this is a string"
>>> a = a.split(" ") # a is converted to a list of strings.
>>> print a
['this', 'is', 'a', 'string']
Joining a string is simple:
>>> a = "-".join(a)
>>> print a
>>>>a="Mahesh"
 a=list(a) # this will split a by character
 >>>> a
   ['M','a','h','e','s','h']
```
_Slicing a String_

We have seen that lists are mutable (they can be changed), and tuples are immutable (they cannot be changed).
Let's try to understand this with an example.
You are given an immutable string, and you want to make changes to it.
Example

```python
>>> string = "abracadabra"
You can access an index by:
>>> print string[5]
a
What if you would like to assign a value?
>>> string[5] = 'k'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'str' object does not support item assignment
```

How would you approach this?
One solution is to convert the string to a list and then change the value.

Example
```python
>>> string = "abracadabra"
>>> l = list(string)
>>> l[5] = 'k'
>>> string = ''.join(l)
>>> print string
abrackdabra
Another approach is to slice the string and join it back.
Example
>>> string = string[:5] + "k" + string[6:]
>>> print string
abrackdabra

this-is-a-string
```

#### JSON IN python

```python
json.load(f) - load json data from a file
json.loads(s) - load json data from a  string
json.dump(j,f) - write json object to file or file like like object
json.dump(j) - output json object as a string
```

### FILE operations
```python
f=open("file.txt",mode)  #modes:r,w,a
text=f.read()
f.write(text)
print("text",file=f)
f.close()
```

#### Text Wrap in python

The textwrap module provides two convenient functions: wrap() and fill().


_textwrap.wrap()_

The wrap() function wraps a single paragraph in text (a string) so that every line is width characters long at most.
It returns a list of output lines.

```python
>>> import textwrap
>>> string = "This is a very very very very very long string."
>>> print textwrap.wrap(string,8)
['This is', 'a very', 'very', 'very', 'very', 'very', 'long', 'string.']

textwrap.fill()
The fill() function wraps a single paragraph in text and returns a single string containing the wrapped paragraph.

>>> import textwrap
>>> string = "This is a very very very very very long string."
>>> print textwrap.fill(string,8)
This is
a very
very
very
very
very
long
string.
```

#### Class and Objects in python

```python
class employee:
	emp1=employee()  #1st instance of class
    emp2=employee()  #2nd instance of class

    # variables in class
    emp1.first="john"
    emp1.last="cena"
```
