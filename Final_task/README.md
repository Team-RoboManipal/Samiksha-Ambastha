# Monocular Depth Estimation using PyTorch

A deep learning project that predicts depth maps from single RGB images using a custom encoder-decoder CNN architecture trained on the NYU Depth Dataset. The model learns spatial and structural features from monocular images to estimate scene depth with high-quality reconstruction.

The project uses a U-Net style architecture with skip connections, edge-aware loss functions, and image enhancement techniques to improve depth estimation quality.

---

## Features

* Custom Encoder-Decoder CNN (U-Net style) architecture
* Skip connections for preserving spatial information
* Monocular depth estimation from a single RGB image
* Edge-aware + smoothness loss for sharper predictions
* Data augmentation using random horizontal flips
* Depth enhancement with OpenCV preprocessing
* Bilateral filtering and CLAHE enhancement
* AdamW optimizer with learning rate scheduler
* GPU (CUDA) and CPU support
* Real-time depth map visualization
* Training and inference pipeline included

---

## Model Architecture

The model follows an encoder-decoder architecture inspired by U-Net.

### Encoder

* Multiple convolutional blocks
* Progressive downsampling
* Feature extraction at different spatial scales

### Bottleneck

* Deep feature representation
* Captures semantic and contextual scene information

### Decoder

* Transpose convolution based upsampling
* Reconstruction of spatial resolution
* Feature fusion using skip connections

### Skip Connections

Skip connections transfer low-level spatial details from encoder layers to decoder layers, improving edge preservation and reconstruction quality.

### Output Layer

* Final Sigmoid activation
* Produces normalized depth maps

---

## Tech Stack

### Programming Language

* Python

### Deep Learning

* PyTorch

### Computer Vision

* OpenCV

### Data Processing

* NumPy

### Visualization

* Matplotlib

### Utilities

* tqdm

---

## Dataset

### NYU Depth Dataset

The project is trained using the NYU Depth Dataset, which contains paired:

* RGB indoor scene images
* Ground truth depth maps

The dataset provides diverse indoor environments useful for monocular depth estimation tasks.

### Dataset Structure

```text
dataset/
│
├── train/
│   ├── images/
│   └── depths/
│
├── val/
│   ├── images/
│   └── depths/
│
└── test/
    ├── images/
    └── depths/
```

---

## Training Pipeline

### Preprocessing

* Image resizing
* Normalization
* Depth scaling
* CLAHE enhancement
* Bilateral filtering

### Data Augmentation

* Random horizontal flipping
* Improved generalization performance

### Optimization

* AdamW optimizer
* Learning rate scheduler
* Mini-batch gradient descent

### Loss Functions

The project combines:

* Edge-aware loss
* Smoothness loss
* Pixel reconstruction loss

This helps produce:

* Sharper boundaries
* Smoother depth transitions
* Better structural consistency

---

## Inference Pipeline

The trained model:

1. Accepts a single RGB image
2. Processes it through the encoder-decoder network
3. Generates a depth map
4. Applies optional enhancement filters
5. Displays or saves the predicted depth output

---

## Results

The model successfully learns scene geometry and depth relationships from monocular RGB inputs.

### Capabilities

* Indoor depth estimation
* Object distance understanding
* Structural scene reconstruction
* Edge-preserving depth prediction

### Output

* High-resolution normalized depth maps
* Improved spatial consistency using skip connections

---

## Applications

* Autonomous navigation
* Robotics perception
* Augmented reality
* 3D scene reconstruction
* SLAM systems
* Obstacle detection
* Indoor mapping
* Computer vision research

---

## Future Improvements

* Attention mechanisms
* Vision Transformer integration
* Multi-scale feature fusion
* Real-time inference optimization
* Mobile deployment
* Better outdoor scene generalization
* Depth uncertainty estimation
* Advanced augmentation strategies

---

## Learning Outcomes

This project demonstrates:

* Deep learning for computer vision
* CNN architecture design
* Encoder-decoder networks
* Skip connection implementation
* Depth estimation concepts
* PyTorch model training
* Image preprocessing techniques
* Loss function engineering
* GPU-based training workflows

---

## Installation

### Clone the Repository

Clone the repository and navigate to the project directory.

### Install Dependencies

Install the required Python packages including:

* PyTorch
* OpenCV
* NumPy
* Matplotlib
* tqdm

### Run Training

Train the model on the NYU Depth Dataset using the training script.

### Run Inference

Load the trained model weights and perform depth estimation on custom RGB images.

---

## Project Structure

```text
project/
│
├── dataset/
├── models/
├── training/
├── inference/
├── utils/
├── outputs/
├── checkpoints/
└── README.md
```

---

