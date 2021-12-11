// Body Mass Index
float calc_bmi(float weight, float height) {
  return (weight / height / height);
}

// 適正体重の計算
float calc_appropriate_weight(float height) {
  return (height * height * 22);
}