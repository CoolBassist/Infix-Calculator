//
// Created by CoolBassist on 05/09/2022.
//

#define _USE_MATH_DEFINES

#include "Evaluator.h"
#include "Error.h"
#include <cmath>
#include <iostream>
#include <variant>

std::tuple<double, double, bool> Evaluator::get_numbers() {
  double num1, num2;
  bool num2_int, num1_int;

  num2_int = std::holds_alternative<IntObject>(output.top());
  if (num2_int) {
    num2 = std::get<IntObject>(output.top()).get_value();
  } else {
    num2 = std::get<RealObject>(output.top()).get_value();
  }

  output.pop();
  num1_int = std::holds_alternative<IntObject>(output.top());
  if (num1_int) {
    num1 = std::get<IntObject>(output.top()).get_value();
  } else {
    num1 = std::get<RealObject>(output.top()).get_value();
  }

  output.pop();

  return std::make_tuple(num1, num2, num1_int || num2_int);
}

std::tuple<double, bool> Evaluator::get_single_number() {
  bool is_int = std::holds_alternative<IntObject>(output.top());
  double value = is_int ? std::get<IntObject>(output.top()).get_value()
                        : std::get<RealObject>(output.top()).get_value();
  output.pop();
  return std::make_tuple(value, is_int);
}

Evaluator::Evaluator(std::vector<Object> objects) { this->objects = objects; }
double Evaluator::get_result() {
  for (Object obj : objects) {
    if (std::holds_alternative<IntObject>(obj)) {
      output.push(std::get<IntObject>(obj));
    } else if (std::holds_alternative<RealObject>(obj)) {
      output.push(std::get<RealObject>(obj));
    } else {
      switch (std::get<OpObject>(obj).get_type()) {
      case ADD: {
        const auto [num1, num2, is_real] = get_numbers();

        if (!is_real) {
          output.push(IntObject(num1 + num2, std::to_string(num1 + num2)));
        } else {
          output.push(RealObject(num1 + num2, std::to_string(num1 + num2)));
        }

        break;
      }
      case SUB: {
        const auto [num1, num2, is_real] = get_numbers();

        if (!is_real) {
          output.push(IntObject(num1 - num2, std::to_string(num1 - num2)));
        } else {
          output.push(RealObject(num1 - num2, std::to_string(num1 - num2)));
        }
        break;
      }
      case MULT: {
        const auto [num1, num2, is_real] = get_numbers();

        if (!is_real) {
          output.push(IntObject(num1 * num2, std::to_string(num1 * num2)));
        } else {
          output.push(RealObject(num1 * num2, std::to_string(num1 * num2)));
        }
        break;
      }
      case DIV: {
        const auto [num1, num2, is_real] = get_numbers();

        if (num2 == 0) {
          std::cout << Error(DIV_BY_0, "0", 0).get_error();
          return NULL;
        }

        output.push(RealObject(num1 / num2, std::to_string(num1 / num2)));
        break;
      }
      case EXP: {
        const auto [num1, num2, is_real] = get_numbers();

        if (!is_real) {
          output.push(IntObject(std::pow(num1, num2),
                                std::to_string(std::pow(num1, num2))));
        } else {
          output.push(RealObject(std::pow(num1, num2),
                                 std::to_string(std::pow(num1, num2))));
        }
        break;
      }
      case SIN: {
        const auto [num1, is_int] = get_single_number();

        output.push(RealObject(std::sin((M_PI / 180) * num1),
                               std::to_string(std::sin(M_PI / 180) * num1)));
        break;
      }
      case COS: {
        const auto [num1, is_int] = get_single_number();

        output.push(RealObject(std::cos((M_PI / 180) * num1),
                               std::to_string(std::cos(M_PI / 180) * num1)));
        break;
      }
      case TAN: {
        const auto [num1, is_int] = get_single_number();

        output.push(RealObject(std::tan((M_PI / 180) * num1),
                               std::to_string(std::tan(M_PI / 180) * num1)));
        break;
      }
      case LOG: {
        const auto [num1, is_int] = get_single_number();

        output.push(
            RealObject(std::log10(num1), std::to_string(std::log10(num1))));
        break;
      }
      case SQR: {
        const auto [num1, is_int] = get_single_number();

        output.push(
            RealObject(std::sqrt(num1), std::to_string(std::sqrt(num1))));
        break;
      }
      }
    }
  }

  if (std::holds_alternative<IntObject>(output.top())) {
    return std::get<IntObject>(output.top()).get_value();
  } else {
    return std::get<RealObject>(output.top()).get_value();
  }
}