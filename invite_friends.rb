require 'json'   #Need for reading json
include Math     #Need for calculating sin(),cos() etc.

$pi= 3.14159265358979323846 #value of pi
#office co-ordinates
$myLat=28.521134   
$myLong=77.206567

#convert degree to radians
def deg2rad(deg)   
return (deg * $pi / 180);
end
#partition algo of quick sort
def partition(arr, left, right)
  pivot = arr[right]['id']
  brk_pt = left

  (left..right-1).each do |i|
    if arr[i]['id'] < pivot
      arr[i], arr[brk_pt] = arr[brk_pt], arr[i]
      brk_pt = brk_pt + 1
    end
  end

  arr[brk_pt], arr[right] = arr[right], arr[brk_pt]
  return brk_pt
end
#Implementation of quick sort
def sortById(arr, left, right)
  if left < right
    
    pi = partition(arr, left, right)
    sortById(arr, left, pi - 1)
    sortById(arr, pi + 1, right)
  end

  return arr
end
#checking if friends lies in 100km radius or not
def valid(id_lat,id_long)
           theta= (id_long-$myLong).abs #absolute of long
            dist = acos(sin(deg2rad(id_lat)) * sin(deg2rad($myLat)) + cos(deg2rad(id_lat)) * cos(deg2rad($myLat)) * cos(deg2rad(theta)))
           dist=dist*6371  #multiplying by earth's radius to get the distance
		   if (dist<=100)
		      return true
		   else 
		      return false
		   end
end


file = File.read('generated.json')
frnd_data = JSON.parse(file)
frnd_data.delete_if do |person|     #delete the friend from data if he is not in the radius of 100km
  if  (valid person['latitude'],person['longitude'] )==false 
  true
  end
end
size=frnd_data.size
size=size-1
 sortById(frnd_data,0,size)  #sorting by id
 puts " ID | \t Name "  #displaying friends who live in the radius of 100km
 frnd_data.each do |i|
puts " #{i['id']} : \t #{i['name']} "
end