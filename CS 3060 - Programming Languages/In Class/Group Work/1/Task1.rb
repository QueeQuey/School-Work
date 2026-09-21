# frozen_string_literal: true

price=[400, 80, 2, 60, 50, 3, 40]
i=0
sum=0
while i<7
  sum+=price[i]
  i+=1
end
avg = sum/7
p "Average price is #{avg}"

priceMap = {"computer" => 400, "board" => 80, "Pen" => 2, "Chair" => 60, "Desk" => 50, "Eraser" => 3, "Light" => 40}
chairPrice = priceMap["Chair"]
deskPrice = priceMap["Desk"]
total = chairPrice + deskPrice
p "Total price of chair and desk is #{total}"