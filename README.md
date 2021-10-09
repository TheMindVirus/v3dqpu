# v3dqpu
Graphics Infrastructure Development of Full-Display-And-Render-Driver for Raspberry Pi 4 running Windows 10

## WARNING!: Please Do Not Install The Driver On Your Raspberry Pi! (Exception: Development)
The solution is in an experimental state and has untested code which is intended for 8x QPU cores. \
Alongside this test are full skeleton boilerplates for DxgkDdi and D3dDdi aiming for WDDM 2.6 support. \
Documentation for DXVA 2.0 has also been included in the hope that the H.264 hardware will be of use.

# Direct3D
Direct3D presents the following HLSL-Based infrastructure to applications and graphics hardware:
 * Vertex Shader - Handles individual points in 3D space for the next pipeline stage
 * Pixel/Fragment Shader - Handles shading of 2D face regions marked by groups of points in 3D space
 * Hull Tessellation Shader - Maps the vertices to 3D texture constructs called Patches
 * Domain Tessellation Shader - Collects vertices from smoothing functions (e.g. Bezier) created from the patches
 * Geometry Tessellation Shader - Applies Stream Modifiers to the vertices to conform to a certain shape
 * Compute Shader - A Multi-purpose re-programmable Shader capable of performing user-specified procedures
 * Input Assembler - Manages ID's of all of the constructs passed through the pipeline
 * Constant/Uniform Buffer - Data Input Area that remains the same during the lifecycle of a shader
 * Counter/Scoreboard - Keeps track of completed and pending operations in the pipeline
 * Tiles/Bins - A method for dividing the work equally and fairly over multiple cores
 * Rasterisation - Reproducing the final image from the output of the pipeline
 * Viewport - Data Output Area of certain dimensions and location that receives the final image
 * Resources - Abstraction for Data and Processes that shaders may be able to consume or copy
 * Command Lists - Sequencing and Macro Control of collections of multiple graphics processes
 * Query Interface - Filtering and Selection of Data based on Predicate Logic and Query Language
 * States & Caches - Behaviour of current processes conditional on previously stored data labels
 * Video Codecs - Converting Audio-Visual Data from one format to another on-batch and real-time

These Drivers can take one of these major forms:
 * Infrastructure Driver - Connects with C-Style Method Callbacks [CB] (e.g. DirectX)
 * Interface Driver - Connects with File Pipes and Socket-Based I/O Control Codes [IOCTL] (e.g. OpenGL)
 * Compiler Driver - Connects with a String-Based Language and Memory Mapped I/O [MMIO] (e.g. Vulkan)
 * Diagnostic Driver - No Connection to Hardware, only Serial Port Logging [UART] (e.g. Software Emulation)

# Intentions
 * The Raspberry Pi 4's 16x QPU cores must be connected to a DirectX Render Class Driver.
 * The Raspberry Pi 4's H.264, VPU and ISP cores should connect to DirectX Video Acceleration.
 * The QPU Example Code in the hello_fft Raspberry Pi Userland Sample has partially been ported.
 * The H.264 Example Code in the hello_video Raspberry Pi Userland Sample should be ported.
 * Power and Clock Domain Management should also be a consideration in developing compliant drivers.
 * Any other hardware ties that can be made available to Windows with frameworks should also be included.