# Monocular Depth Estimation using PyTorch 🧠📏

A deep learning project that predicts depth maps from single RGB images using a custom encoder-decoder CNN architecture trained on the NYU Depth dataset.

---

## 🚀 Features

- Custom **Encoder-Decoder CNN (U-Net style)** architecture
- Skip connections for better spatial detail preservation
- Edge-aware + smoothness loss for sharper depth maps
- Data augmentation (random flips)
- Depth enhancement using OpenCV (CLAHE + bilateral filtering)
- Training with **AdamW optimizer + LR scheduler**
- Works on GPU (CUDA) or CPU

---

## 🧠 Model Architecture

- Multi-stage **downsampling (encoder)** with convolution blocks
- Bottleneck layer for deep feature extraction
- **Upsampling (decoder)** using transpose convolutions
- Skip connections for fine-grained reconstruction
- Final **Sigmoid output** for normalized depth prediction

---

## 🛠️ Tech Stack

- Python
- PyTorch
- OpenCV
- NumPy
- Matplotlib
- tqdm

---

## 📂 Dataset

- **NYU Depth Dataset**
- Structure:
