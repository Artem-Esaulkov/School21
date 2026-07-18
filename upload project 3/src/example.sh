#!/bin/bash

WIDTH=50       # ширина графика
HEIGHT=20     # высота графика
X_MIN=-3
X_MAX=3

for ((row=1; row<=HEIGHT; row++)); do
  # Вычисляем текущий y-уровень
  # Высота с верху (row=1) до низа (row=HEIGHT)
  y_level=$(echo "$HEIGHT - $row" | bc)

  line=""
  for ((col=0; col<WIDTH; col++)); do
    # Выбираем x по ширине
    x=$(echo "$X_MIN + ($X_MAX - $X_MIN)*$col/$WIDTH" | bc -l)
    # Вычисляем y
    y=$(echo "scale=4; 1/(1 + $x*$x)" | bc -l)

    # Масштабируем y по высоте графика
    # Максимальное y=1, минимальное=0
    y_scaled=$(echo "$y * ($HEIGHT-1)" | bc -l)

    # Если в этой строке находится значение y примерно равно y_scaled (с погрешностью)
    diff=$(echo "$y_scaled - $y_level" | bc -l)
    abs_diff=$(echo "$diff" | awk '{print ($0<0)?-$0:$0}')

    # Порог для отображения
    if (( $(echo "$abs_diff < 0.5" | bc -l) )); then
      line+="*"
    else
      line+=" "
    fi
  done
  echo "$line"
done
