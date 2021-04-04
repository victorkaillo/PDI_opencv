## Atividades relativa

You can use the [editor on GitHub](https://github.com/victorkaillo/PDI_opencv/edit/gh-pages/index.md) to maintain and preview the content for your website in Markdown files.

### Programa negativo de região
Utilizando o programa exemplos/pixels.cpp como referência, implemente um programa regions.cpp. Esse programa deverá solicitar ao usuário as coordenadas de dois pontos 𝑃1 e 𝑃2 localizados dentro dos limites do tamanho da imagem e exibir que lhe for fornecida. Entretanto, a região definida pelo retângulo de vértices opostos definidos pelos pontos 𝑃1 e 𝑃2 será exibida com o negativo da imagem na região correspondente. O efeito é ilustrado na Figura 4.

```c
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
  cv::Mat image;
  cv::Vec3b val;

  image= cv::imread("biel.png",cv::IMREAD_GRAYSCALE);
  if(!image.data)
    std::cout << "nao abriu bolhas.png" << std::endl;

  cv::namedWindow("janela", cv::WINDOW_AUTOSIZE);

  int x1, x2, y1, y2;

  cout << "O tamanho da imagem é: ";
  cout << image.size().height << "/"<< image.size().width << endl;
  cout << "Escreva pontos dentro desse limite."<< endl;

  cout << "digite o x do primeiro par ordenado:" << endl;
  cin >> x1;
  cout << "digite o y do primeiro par ordenado:" << endl;
  cin >> y1;
  cout << "digite o x do segundo par ordenado:" << endl;
  cin >> x2;
  cout << "digite o y do segundo par ordenado:" << endl;
  cin >> y2;



  /*for(int i=200;i<210;i++){
    for(int j=10;j<200;j++){
      image.at<uchar>(i,j)=0;
    }
  }
  
  cv::imshow("janela", image);  
  cv::waitKey(0);*/
  //cv::waitKey();

  //image= cv::imread("bolhas.png",cv::IMREAD_COLOR);
/*
  val[0] = 0;   //B
  val[1] = 255;   //G
  val[2] = 0; //R
  
  for(int i=200;i<210;i++){
    for(int j=10;j<200;j++){
      image.at<Vec3b>(i,j)=val;
    }
  }

  cv::imshow("janela", image);  
  cv::waitKey(0);*/

  for(int i=x1; i< x2; i++){
    for(int j=y1; j< y2; j++){
      image.at<uchar>(i,j)=255-image.at<uchar>(i,j);
    }
  }

  imwrite("regioes.png", image);
  imshow("janela", image);
  waitKey();



  //cv::waitKey(-1);
  return 0;
}

```

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/victorkaillo/PDI_opencv/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
