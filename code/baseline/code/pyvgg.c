#include "tw_vgg10.h"
#include <stdio.h>

#define OUTPUT_LEN 1
#define OUTPUT_FILT 4


int main( int argc, char ** argv ) {

	//input image
	float input_img_test[IMG_LEN * IMG_FILT] = { 0.359375, -0.125, 0.5625, -0.265625, 0.6875, -0.359375, 0.734375, -0.390625, 0.703125, -0.359375, 0.5625, -0.265625, 0.359375, -0.140625, 0.125, 0.03125, -0.15625, 0.203125, -0.390625, 0.375, -0.59375, 0.5, -0.734375, 0.59375, -0.765625, 0.609375, -0.734375, 0.59375, -0.59375, 0.5, -0.390625, 0.359375, -0.140625, 0.1875, 0.140625, 0.015625, 0.421875, -0.171875, 0.671875, -0.34375, 0.875, -0.484375, 1.03125, -0.578125, 1.125, -0.65625, 1.171875, -0.671875, 1.171875, -0.671875, 1.125, -0.65625, 1.078125, -0.609375, 1.015625, -0.578125, 0.953125, -0.53125, 0.90625, -0.5, 0.875, -0.484375, 0.859375, -0.46875, 0.859375, -0.46875, 0.859375, -0.46875, 0.859375, -0.484375, 0.875, -0.484375, 0.875, -0.484375, 0.859375, -0.484375, 0.859375, -0.46875, 0.859375, -0.46875, 0.859375, -0.484375, 0.875, -0.484375, 0.90625, -0.515625, 0.953125, -0.546875, 1.0, -0.578125, 1.0625, -0.625, 1.125, -0.65625, 1.15625, -0.6875, 1.15625, -0.6875, 1.125, -0.65625, 1.015625, -0.59375, 0.859375, -0.484375, 0.65625, -0.34375, 0.40625, -0.171875, 0.125, 0.015625, -0.15625, 0.203125, -0.40625, 0.359375, -0.609375, 0.5, -0.734375, 0.578125, -0.765625, 0.609375, -0.703125, 0.5625, -0.5625, 0.46875, -0.34375, 0.328125, -0.09375, 0.15625, 0.171875, -0.015625, 0.390625, -0.171875, 0.5625, -0.28125, 0.640625, -0.34375, 0.625, -0.328125, 0.515625, -0.265625, 0.328125, -0.140625, 0.09375, 0.03125, -0.15625, 0.203125, -0.390625, 0.359375, -0.578125, 0.484375, -0.671875, 0.546875, -0.671875, 0.546875, -0.578125, 0.484375, -0.40625, 0.359375, -0.171875, 0.203125, 0.09375, 0.03125, 0.328125, -0.125, 0.515625, -0.265625, 0.625, -0.34375, 0.65625, -0.34375, 0.578125, -0.296875, 0.40625, -0.1875, 0.1875, -0.03125, -0.078125, 0.140625, -0.328125, 0.3125, -0.5625, 0.46875, -0.71875, 0.578125, -0.796875, 0.625, -0.78125, 0.609375, -0.671875, 0.546875, -0.46875, 0.40625, -0.21875, 0.234375, 0.078125, 0.03125, 0.375, -0.171875, 0.6875, -0.375, 0.953125, -0.5625, 1.171875, -0.71875, 1.328125, -0.8125, 1.40625, -0.875, 1.40625, -0.875, 1.328125, -0.828125, 1.171875, -0.71875, 0.953125, -0.578125, 0.6875, -0.390625, 0.390625, -0.1875, 0.09375, 0.03125, -0.203125, 0.21875, -0.453125, 0.40625, -0.65625, 0.53125, -0.765625, 0.609375, -0.8125, 0.640625, -0.75, 0.59375, -0.609375, 0.5, -0.40625, 0.359375, -0.15625, 0.1875, 0.109375, 0.015625, 0.34375, -0.15625, 0.546875, -0.296875, 0.6875, -0.390625, 0.75, -0.4375, 0.703125, -0.40625, 0.59375, -0.328125, 0.390625, -0.1875, 0.140625, -0.015625, -0.15625, 0.1875, -0.453125, 0.390625, -0.734375, 0.578125, -0.984375, 0.765625, -1.1875, 0.890625, -1.328125, 1.0, -1.390625, 1.046875, -1.390625, 1.046875, -1.34375, 1.0, -1.21875, 0.921875, -1.046875, 0.796875, -0.84375, 0.65625, -0.609375, 0.5, -0.359375, 0.3125, -0.09375, 0.140625, 0.15625, -0.03125, 0.390625, -0.1875, 0.59375, -0.328125, 0.765625, -0.453125, 0.90625, -0.546875, 1.0, -0.609375, 1.046875, -0.65625, 1.0625, -0.671875, 1.0625, -0.65625, 1.03125, -0.640625, 1.0, -0.609375, 0.953125, -0.59375, 0.90625, -0.5625, 0.890625, -0.53125, 0.859375, -0.53125, 0.84375, -0.515625, 0.84375, -0.515625, 0.84375, -0.515625, 0.84375, -0.515625, 0.859375, -0.515625, 0.859375, -0.515625, 0.84375, -0.515625, 0.84375, -0.515625, 0.84375, -0.515625, 0.84375, -0.515625, 0.859375, -0.53125, 0.875, -0.546875, 0.921875, -0.5625, 0.953125, -0.59375, 1.0, -0.625, 1.046875, -0.65625, 1.0625, -0.671875, 1.078125, -0.671875, 1.046875, -0.65625, 0.984375, -0.625, 0.875, -0.546875, 0.734375, -0.4375, 0.546875, -0.3125, 0.328125, -0.15625, 0.09375, 0.015625, -0.15625, 0.171875, -0.390625, 0.34375, -0.609375, 0.5, -0.796875, 0.625, -0.953125, 0.734375, -1.0625, 0.8125, -1.125, 0.859375, -1.140625, 0.875, -1.140625, 0.859375, -1.109375, 0.84375, -1.0625, 0.8125, -1.015625, 0.78125, -0.96875, 0.75, -0.9375, 0.71875, -0.90625, 0.703125, -0.890625, 0.703125, -0.890625, 0.703125, -0.90625, 0.703125, -0.921875, 0.703125, -0.921875, 0.71875, -0.9375, 0.734375, -0.96875, 0.734375, -0.96875, 0.75, -0.96875, 0.75, -0.96875, 0.75, -0.96875, 0.75, -0.953125, 0.734375, -0.9375, 0.734375, -0.921875, 0.71875, -0.90625, 0.703125, -0.890625, 0.6875, -0.890625, 0.6875, -0.890625, 0.6875, -0.90625, 0.703125, -0.9375, 0.71875, -0.984375, 0.75, -1.03125, 0.796875, -1.09375, 0.84375, -1.15625, 0.875, -1.1875, 0.90625, -1.1875, 0.90625, -1.15625, 0.875, -1.0625, 0.8125, -0.921875, 0.71875, -0.734375, 0.578125, -0.5, 0.421875, -0.25, 0.234375, 0.03125, 0.046875, 0.28125, -0.140625, 0.484375, -0.28125, 0.640625, -0.40625, 0.71875, -0.453125, 0.734375, -0.453125, 0.640625, -0.40625, 0.484375, -0.296875, 0.28125, -0.140625, 0.03125, 0.03125, -0.234375, 0.234375, -0.5, 0.40625, -0.734375, 0.578125, -0.921875, 0.71875, -1.0625, 0.8125, -1.15625, 0.875, -1.1875, 0.90625, -1.1875, 0.90625, -1.15625, 0.875, -1.09375, 0.84375, -1.046875, 0.796875, -0.984375, 0.765625, -0.953125, 0.734375, -0.921875, 0.71875, -0.90625, 0.703125, -0.890625, 0.703125, -0.90625, 0.703125, -0.90625, 0.703125, -0.90625, 0.703125, -0.90625, 0.703125, -0.90625, 0.703125, -0.90625, 0.703125, -0.890625, 0.703125, -0.90625, 0.703125, -0.921875, 0.703125, -0.953125, 0.734375, -0.984375, 0.765625, -1.046875, 0.796875, -1.109375, 0.84375, -1.15625, 0.890625, -1.203125, 0.90625, -1.203125, 0.90625, -1.15625, 0.890625, -1.0625, 0.8125, -0.921875, 0.703125, -0.71875, 0.5625, -0.46875, 0.390625, -0.203125, 0.1875, 0.078125, -0.0, 0.3125, -0.1875, 0.515625, -0.328125, 0.640625, -0.421875, 0.6875, -0.453125, 0.65625, -0.421875, 0.53125, -0.328125, 0.328125, -0.1875, 0.09375, -0.015625, -0.171875, 0.171875, -0.40625, 0.34375, -0.609375, 0.484375, -0.734375, 0.578125, -0.765625, 0.609375, -0.71875, 0.578125, -0.59375, 0.484375, -0.390625, 0.328125, -0.15625, 0.15625, 0.109375, -0.03125, 0.375, -0.234375, 0.609375, -0.390625, 0.796875, -0.53125, 0.9375, -0.625, 1.015625, -0.6875, 1.046875, -0.71875, 1.046875, -0.71875, 1.03125, -0.703125, 1.0, -0.6875, 0.984375, -0.671875, 0.984375, -0.671875, 1.0, -0.6875, 1.03125, -0.703125, 1.046875, -0.71875, 1.046875, -0.71875, 1.015625, -0.6875, 0.921875, -0.640625, 0.796875, -0.53125, 0.609375, -0.40625, 0.375, -0.21875, 0.109375, -0.03125, -0.15625, 0.15625, -0.40625, 0.34375, -0.59375, 0.484375, -0.71875, 0.5625, -0.765625, 0.59375, -0.71875, 0.5625, -0.578125, 0.46875, -0.375, 0.3125, -0.125, 0.140625, 0.125, -0.046875, 0.359375, -0.21875, 0.515625, -0.34375, 0.625, -0.40625, 0.625, -0.421875, 0.53125, -0.359375, 0.375, -0.234375, 0.140625, -0.0625, -0.109375, 0.125, -0.359375, 0.296875, -0.578125, 0.453125, -0.71875, 0.5625, -0.796875, 0.625, -0.78125, 0.609375, -0.671875, 0.53125, -0.484375, 0.390625, -0.234375, 0.21875, 0.046875, 0.0, 0.359375, -0.21875, 0.640625, -0.4375, 0.90625, -0.625, 1.125, -0.78125, 1.265625, -0.90625, 1.34375, -0.953125, 1.359375, -0.953125, 1.28125, -0.90625, 1.125, -0.796875, 0.921875, -0.640625, 0.65625, -0.453125, 0.359375, -0.234375, 0.0625, -0.015625, -0.21875, 0.203125, -0.46875, 0.375, -0.671875, 0.515625, -0.78125, 0.609375, -0.8125, 0.640625, -0.75, 0.59375, -0.625, 0.484375, -0.421875, 0.34375, -0.171875, 0.15625, 0.078125, -0.03125, 0.3125, -0.203125, 0.515625, -0.34375, 0.65625, -0.453125, 0.703125, -0.484375, 0.671875, -0.46875, 0.546875, -0.375, 0.359375, -0.234375, 0.109375, -0.046875, -0.171875, 0.15625, -0.46875, 0.375, -0.734375, 0.578125, -0.984375, 0.765625, -1.1875, 0.90625, -1.3125, 1.0, -1.390625, 1.0625, -1.390625, 1.0625, -1.328125, 1.015625, -1.203125, 0.921875, -1.046875, 0.796875, -0.84375, 0.65625, -0.609375, 0.484375, -0.375, 0.296875, -0.109375, 0.109375, 0.125, -0.0625, 0.359375, -0.234375, 0.5625, -0.390625, 0.71875, -0.515625, 0.859375, -0.609375, 0.953125, -0.6875, 1.015625, -0.734375, 1.03125, -0.75, 1.03125, -0.734375, 1.0, -0.71875, 0.953125, -0.6875, 0.890625, -0.640625, 0.828125, -0.609375, 0.78125, -0.5625, 0.75, -0.53125, 0.734375, -0.515625, 0.734375, -0.515625, 0.75, -0.53125, 0.796875, -0.5625, 0.859375, -0.609375, 0.921875, -0.671875, 0.984375, -0.71875, 1.046875, -0.765625, 1.09375, -0.796875, 1.09375, -0.796875, 1.0625, -0.765625, 0.953125, -0.703125, 0.8125, -0.59375, 0.609375, -0.4375, 0.359375, -0.25, 0.09375, -0.046875, -0.171875, 0.140625, -0.421875, 0.328125, -0.609375, 0.484375, -0.734375, 0.578125, -0.78125, 0.609375, -0.734375, 0.578125, -0.609375, 0.484375, -0.421875, 0.34375, -0.1875, 0.15625, 0.0625, -0.03125, 0.296875, -0.21875, 0.5, -0.359375, 0.625, -0.453125, 0.65625, -0.484375, 0.609375, -0.453125, 0.484375, -0.34375, 0.296875, -0.203125, 0.046875, -0.015625, -0.21875, 0.171875, -0.46875, 0.375, -0.703125, 0.546875, -0.890625, 0.6875, -1.015625, 0.78125, -1.09375, 0.84375, -1.140625, 0.875, -1.140625, 0.875, -1.109375, 0.859375, -1.09375, 0.84375, -1.078125, 0.828125, -1.078125, 0.828125, -1.09375, 0.84375, -1.109375, 0.859375, -1.125, 0.859375, -1.125, 0.859375, -1.09375, 0.84375, -1.015625, 0.78125, -0.90625, 0.703125, -0.734375, 0.5625, -0.515625, 0.40625, -0.265625, 0.21875, -0.015625, 0.015625, 0.234375, -0.171875, 0.4375, -0.328125, 0.59375, -0.4375, 0.6875, -0.5, 0.6875, -0.515625, 0.609375, -0.453125, 0.453125, -0.34375, 0.25, -0.1875, 0.0, 0.0, -0.25, 0.203125, -0.515625, 0.390625, -0.734375, 0.578125, -0.921875, 0.71875, -1.078125, 0.828125, -1.15625, 0.890625, -1.203125, 0.921875, -1.1875, 0.921875, -1.15625, 0.890625, -1.09375, 0.84375, -1.03125, 0.796875, -0.953125, 0.734375, -0.890625, 0.6875, -0.84375, 0.65625, -0.828125, 0.640625, -0.828125, 0.640625, -0.84375, 0.65625, -0.890625, 0.6875, -0.953125, 0.734375, -1.03125, 0.796875, -1.109375, 0.859375, -1.171875, 0.90625, -1.203125, 0.9375, -1.203125, 0.9375, -1.171875, 0.90625, -1.078125, 0.828125, -0.921875, 0.703125, -0.71875, 0.546875, -0.46875, 0.375, -0.203125, 0.15625, 0.0625, -0.046875, 0.296875, -0.234375, 0.5, -0.375, 0.609375, -0.46875, 0.640625, -0.5, 0.59375, -0.453125, 0.453125, -0.34375, 0.25, -0.1875, 0.0, -0.0, -0.25, 0.1875, -0.46875, 0.359375, -0.625, 0.484375, -0.703125, 0.546875, -0.6875, 0.53125, -0.59375, 0.453125, -0.421875, 0.328125, -0.1875, 0.140625, 0.046875, -0.046875, 0.28125, -0.21875, 0.46875, -0.359375, 0.5625, -0.4375, 0.578125, -0.453125, 0.5, -0.390625, 0.34375, -0.265625, 0.125, -0.109375, -0.109375, 0.09375, -0.359375, 0.28125, -0.578125, 0.4375, -0.734375, 0.5625, -0.796875, 0.625, -0.78125, 0.609375, -0.671875, 0.53125, -0.5, 0.390625, -0.25, 0.1875, 0.03125, -0.03125, 0.328125, -0.25, 0.609375, -0.484375, 0.875, -0.6875, 1.078125, -0.84375, 1.234375, -0.953125, 1.3125, -1.015625, 1.3125, -1.015625, 1.234375, -0.96875, 1.078125, -0.84375, 0.875, -0.6875, 0.625, -0.484375, 0.328125, -0.265625, 0.03125, -0.03125, -0.25, 0.1875, -0.5, 0.375, -0.671875, 0.515625, -0.78125, 0.609375, -0.796875, 0.609375, -0.734375, 0.5625, -0.59375, 0.453125, -0.375, 0.28125, -0.140625, 0.09375, 0.109375, -0.09375, 0.328125, -0.265625, 0.5, -0.390625, 0.59375, -0.46875, 0.59375, -0.46875, 0.5, -0.40625, 0.34375, -0.265625, 0.109375, -0.09375, -0.140625, 0.09375, -0.375, 0.28125, -0.578125, 0.453125, -0.734375, 0.5625, -0.796875, 0.609375, -0.78125, 0.59375, -0.671875, 0.515625, -0.484375, 0.359375, -0.234375, 0.171875, 0.03125, -0.046875, 0.328125, -0.265625, 0.59375, -0.484375, 0.828125, -0.671875, 1.03125, -0.8125, 1.15625, -0.921875, 1.21875, -0.96875, 1.21875, -0.984375, 1.171875, -0.9375, 1.0625, -0.84375, 0.90625, -0.734375, 0.71875, -0.578125, 0.515625, -0.40625, 0.28125, -0.234375, 0.03125, -0.046875, -0.203125, 0.140625, -0.4375, 0.328125, -0.65625, 0.5, -0.859375, 0.65625, -1.03125, 0.796875, -1.15625, 0.90625, -1.25, 0.984375, -1.3125, 1.015625, -1.296875, 1.015625, -1.25, 0.96875, -1.15625, 0.90625, -1.015625, 0.78125, -0.828125, 0.640625, -0.625, 0.46875, -0.390625, 0.28125, -0.140625, 0.09375, 0.09375, -0.09375, 0.3125, -0.265625, 0.515625, -0.421875, 0.671875, -0.5625, 0.8125, -0.65625, 0.90625, -0.734375, 0.953125, -0.78125, 0.984375, -0.796875, 0.96875, -0.796875, 0.9375, -0.765625, 0.90625, -0.734375, 0.859375, -0.703125, 0.828125, -0.671875, 0.78125, -0.65625, 0.765625, -0.625, 0.75, -0.625, 0.75, -0.625, 0.75, -0.625, 0.765625, -0.640625, 0.78125, -0.640625, 0.78125, -0.65625, 0.796875, -0.65625, 0.796875, -0.671875, 0.8125, -0.671875, 0.8125, -0.671875, 0.8125, -0.671875, 0.796875, -0.671875, 0.796875, -0.671875, 0.796875, -0.671875, 0.796875, -0.671875, 0.8125, -0.671875, 0.8125, -0.671875, 0.796875, -0.671875, 0.796875, -0.671875, 0.796875, -0.65625, 0.78125, -0.65625, 0.765625, -0.640625, 0.75, -0.625, 0.734375, -0.625, 0.734375, -0.609375, 0.734375, -0.625, 0.75, -0.625, 0.78125, -0.65625, 0.828125, -0.6875, 0.875, -0.734375, 0.9375, -0.78125, 0.984375, -0.828125, 1.015625, -0.84375, 1.03125, -0.859375, 0.984375, -0.828125, 0.90625, -0.75, 0.765625, -0.65625, 0.59375, -0.5, 0.359375, -0.328125, 0.109375, -0.125, -0.140625, 0.078125, -0.375, 0.28125, -0.578125, 0.4375, -0.734375, 0.5625, -0.8125, 0.625, -0.8125, 0.609375, -0.734375, 0.5625, -0.578125, 0.4375, -0.375, 0.265625, -0.140625, 0.078125, 0.109375, -0.125, 0.359375, -0.328125, 0.578125, -0.5, 0.75, -0.640625, 0.859375, -0.734375, 0.9375, -0.796875, 0.96875, -0.8125, 0.96875, -0.8125, 0.953125, -0.796875, 0.921875, -0.78125, 0.890625, -0.765625, 0.875, -0.75, 0.875, -0.75, 0.890625, -0.75, 0.890625, -0.765625, 0.890625, -0.765625, 0.890625, -0.75, 0.84375, -0.71875, 0.765625, -0.65625, 0.65625, -0.5625, 0.5, -0.453125, 0.3125, -0.296875, 0.09375, -0.125, -0.140625, 0.078125, -0.375, 0.265625, -0.609375, 0.46875, -0.828125, 0.640625, -1.015625, 0.78125, -1.15625, 0.90625, -1.265625, 0.984375, -1.3125, 1.03125, -1.3125, 1.03125, -1.265625, 0.984375, -1.15625, 0.90625, -1.015625, 0.78125, -0.828125, 0.640625, -0.609375, 0.46875, -0.390625, 0.265625, -0.140625, 0.078125, 0.09375, -0.109375, 0.3125, -0.296875, 0.5, -0.453125, 0.65625, -0.578125, 0.765625, -0.671875, 0.84375, -0.734375, 0.890625, -0.765625, 0.90625, -0.78125, 0.90625, -0.78125, 0.890625, -0.765625, 0.875, -0.75, 0.859375, -0.75, 0.859375, -0.75, 0.875, -0.75, 0.875, -0.765625, 0.890625, -0.78125, 0.90625, -0.78125, 0.890625, -0.78125, 0.84375, -0.734375, 0.765625, -0.671875, 0.65625, -0.578125, 0.484375, -0.453125, 0.296875, -0.296875, 0.09375, -0.125, -0.140625, 0.078125, -0.390625, 0.265625, -0.609375, 0.453125, -0.828125, 0.640625, -1.015625, 0.78125, -1.15625, 0.90625, -1.25, 0.984375, -1.296875, 1.03125, -1.296875, 1.03125, -1.25, 0.984375, -1.15625, 0.90625, -1.03125, 0.796875, -0.859375, 0.65625, -0.65625, 0.5, -0.4375, 0.3125, -0.203125, 0.125, 0.03125, -0.078125, 0.265625, -0.265625, 0.484375, -0.453125, 0.671875, -0.609375, 0.84375, -0.75, 0.984375, -0.859375, 1.078125, -0.9375, 1.125, -0.984375, 1.125, -0.984375, 1.0625, -0.9375, 0.96875, -0.859375, 0.828125, -0.75, 0.65625, -0.59375, 0.453125, -0.421875, 0.21875, -0.234375, -0.015625, -0.046875, -0.25, 0.15625, -0.46875, 0.328125, -0.671875, 0.5, -0.828125, 0.640625, -0.953125, 0.734375, -1.046875, 0.8125, -1.09375, 0.859375, -1.125, 0.875, -1.109375, 0.875, -1.09375, 0.84375, -1.046875, 0.8125, -1.015625, 0.78125, -0.96875, 0.75, -0.9375, 0.71875, -0.921875, 0.703125, -0.90625, 0.703125, -0.90625, 0.703125, -0.90625, 0.703125, -0.921875, 0.703125, -0.921875, 0.71875, -0.9375, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.75, -0.953125, 0.734375, -0.953125, 0.75, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.9375, 0.734375, -0.9375, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.734375, -0.953125, 0.75, -0.96875, 0.75, -0.953125, 0.75, -0.953125, 0.734375, -0.953125, 0.734375, -0.9375, 0.71875, -0.921875, 0.71875, -0.90625, 0.703125, -0.890625, 0.6875, -0.890625, 0.6875, -0.890625, 0.6875, -0.90625, 0.703125, -0.9375, 0.71875, -0.984375, 0.765625, -1.03125, 0.8125, -1.09375, 0.859375, -1.140625, 0.90625, -1.1875, 0.9375, -1.1875, 0.9375, -1.140625, 0.90625, -1.0625, 0.828125, -0.921875, 0.703125, -0.734375, 0.546875, -0.5, 0.359375, -0.25, 0.140625, 0.015625, -0.078125, 0.25, -0.28125, 0.421875, -0.4375, 0.546875, -0.546875, 0.59375, -0.578125, 0.5625, -0.546875, 0.4375, -0.453125, 0.265625, -0.296875, 0.03125, -0.109375, -0.203125, 0.09375, -0.4375, 0.296875, -0.625, 0.453125, -0.765625, 0.578125, -0.8125, 0.609375, -0.796875, 0.59375, -0.671875, 0.5, -0.5, 0.34375, -0.265625, 0.15625, 0.0, -0.078125, 0.28125, -0.3125, 0.5625, -0.546875, 0.8125, -0.765625, 1.0, -0.9375, 1.15625, -1.0625, 1.21875, -1.125, 1.21875, -1.125, 1.15625, -1.0625, 1.015625, -0.9375, 0.8125, -0.765625, 0.5625, -0.5625, 0.28125, -0.328125, -0.0, -0.078125, -0.28125, 0.15625, -0.515625, 0.359375, -0.6875, 0.515625, -0.78125, 0.59375, -0.8125, 0.609375, -0.734375, 0.546875, -0.59375, 0.4375, -0.390625, 0.265625, -0.15625, 0.0625, 0.078125, -0.140625, 0.28125, -0.328125, 0.4375, -0.46875, 0.53125, -0.53125, 0.53125, -0.53125, 0.4375, -0.453125, 0.28125, -0.3125, 0.0625, -0.140625, -0.171875, 0.0625, -0.40625, 0.265625, -0.59375, 0.4375, -0.71875, 0.546875, -0.78125, 0.578125, -0.75, 0.5625, -0.625, 0.453125, -0.4375, 0.296875, -0.203125, 0.09375, 0.046875, -0.125, 0.28125, -0.328125, 0.5, -0.515625, 0.6875, -0.671875, 0.8125, -0.78125, 0.890625, -0.84375, 0.921875, -0.875, 0.921875, -0.875, 0.90625, -0.859375, 0.875, -0.84375, 0.859375, -0.828125, 0.859375, -0.828125, 0.859375, -0.84375, 0.890625, -0.859375, 0.90625, -0.875, 0.90625, -0.875, 0.875, -0.84375, 0.8125, -0.78125, 0.6875, -0.6875, 0.53125, -0.546875, 0.328125, -0.375, 0.09375, -0.171875, -0.15625, 0.046875, -0.390625, 0.25, -0.578125, 0.421875, -0.734375, 0.546875, -0.8125, 0.609375, -0.8125, 0.609375, -0.734375, 0.546875, -0.578125, 0.421875, -0.390625, 0.25, -0.15625, 0.046875, 0.078125, -0.171875, 0.3125, -0.375, 0.53125, -0.546875, 0.6875, -0.6875, 0.796875, -0.796875, 0.875, -0.859375, 0.90625, -0.875, 0.90625, -0.875, 0.890625, -0.859375, 0.859375, -0.84375, 0.859375, -0.84375, 0.859375, -0.84375, 0.875, -0.859375, 0.890625, -0.875, 0.90625, -0.890625, 0.90625, -0.890625, 0.875, -0.859375, 0.796875, -0.796875, 0.671875, -0.6875, 0.5, -0.53125, 0.28125, -0.34375, 0.03125, -0.125, -0.21875, 0.09375, -0.4375, 0.28125, -0.625, 0.453125, -0.734375, 0.546875, -0.78125, 0.578125, -0.734375, 0.546875, -0.609375, 0.421875, -0.421875, 0.265625, -0.1875, 0.0625, 0.046875, -0.140625, 0.265625, -0.328125, 0.421875, -0.46875, 0.515625, -0.546875, 0.515625, -0.546875, 0.4375, -0.484375, 0.28125, -0.34375, 0.0625, -0.15625, -0.171875, 0.046875, -0.40625, 0.25, -0.59375, 0.421875, -0.734375, 0.546875, -0.8125, 0.609375, -0.796875, 0.59375, -0.6875, 0.5, -0.515625, 0.359375, -0.28125, 0.15625, -0.015625, -0.09375, 0.265625, -0.328125, 0.53125, -0.578125, 0.78125, -0.78125, 0.96875, -0.96875, 1.109375, -1.078125, 1.171875, -1.140625, 1.1875, -1.140625, 1.109375, -1.09375, 0.984375, -0.96875, 0.796875, -0.8125, 0.5625, -0.609375, 0.296875, -0.375, 0.03125, -0.125, -0.234375, 0.09375, -0.46875, 0.296875, -0.65625, 0.46875, -0.78125, 0.578125, -0.84375, 0.640625, -0.828125, 0.625, -0.734375, 0.546875, -0.578125, 0.40625, -0.375, 0.234375, -0.15625, 0.03125, 0.09375, -0.1875, 0.3125, -0.390625, 0.515625, -0.5625, 0.671875, -0.703125, 0.796875, -0.8125, 0.859375, -0.875, 0.890625, -0.890625, 0.875, -0.890625, 0.859375, -0.875, 0.84375, -0.859375, 0.828125, -0.859375, 0.828125, -0.859375, 0.84375, -0.859375, 0.859375, -0.890625, 0.875, -0.90625, 0.875, -0.90625, 0.859375, -0.875, 0.78125, -0.8125, 0.671875, -0.71875, 0.515625, -0.578125, 0.3125, -0.390625, 0.078125, -0.1875, -0.15625, 0.03125};
	//expected output
	float pred_output_test[OUTPUT_LEN * OUTPUT_FILT] = { 3.28125, 0.5, -2.25, 0.71875};


	//expected O/P converted to prediction
	short img_expect[OUTPUT_LEN*OUTPUT_FILT];
	convert_float( pred_output_test, img_expect, ( 1 << PREC ), OUTPUT_LEN, OUTPUT_FILT);

	// input
	int img_len = IMG_LEN;
	short img[img_len*IMG_FILT];
	//"Take in a signal of 1024 I/Q samples in the form [ I0, Q0, I1, Q1, ..., I1023, Q1023 ]"
	convert_float( input_img_test, img, 1 << PREC, img_len, IMG_FILT);

	short output[OUTPUT_LEN * OUTPUT_FILT];

	compute_network(img, output);



	int i,j;
	int fail_cnt = 0;
	for ( i = 0; i < OUTPUT_LEN; i++ ) {
		for ( j = 0; j < OUTPUT_FILT; j++ ) {
			if ( output[i*OUTPUT_FILT+j] != img_expect[i*OUTPUT_FILT+j] ) {
				printf( "FAILED: (%d,%d) where %d != %d\n", i, j, output[i*OUTPUT_FILT+j], img_expect[i*OUTPUT_FILT+j] );
				fail_cnt += 1;
			}
		}
	}
	printf( "%d total fails\n", fail_cnt );

	return 0;
}