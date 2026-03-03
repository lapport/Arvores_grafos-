#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *vetor, int tamanho) {
    int temp, i, j, min_idx;

    for (i = 0; i < tamanho - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }

        // S� troca se necess�rio
        if (min_idx != i) {
            temp = vetor[min_idx];
            vetor[min_idx] = vetor[i];
            vetor[i] = temp;
        }
    }
}

void bubbleSort(int *vetor, int tamanho) {
    int temp, i, j;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {

            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivô escolhido como último elemento
    int i = low - 1;        // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            if (i != j) { 
            }
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Coloca o pivô na posicao correta
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;


    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Funcao para mesclar dois subarrays
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    // Copiando os elementos para os subarrays L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    // Mesclar os dois subarrays ordenados de volta em arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Funcao recursiva MergeSort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void insertionSort(int arr[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        // Mover elementos maiores que a chave para frente
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

void copiarArray(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void preencherAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // valores de 0 a 999
    }
}

int main() {
    int tamanho;
    int opcao;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetorOriginal[tamanho];
    int vetorCopia[tamanho];

    srand(time(NULL));
    preencherAleatorio(vetorOriginal, tamanho);

    do {
        printf("\n===== MENU DE ORDENACAO =====\n");
        printf("1 - Quick Sort\n");
        printf("2 - Merge Sort\n");
        printf("3 - Insertion Sort\n");
        printf("4 - Bubble Sort\n");
		printf("5 - Selection Sort\n");
		printf("6 - Executar TODOS\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        clock_t inicio, fim;
        double tempo;

        switch (opcao) {

        case 1:
            copiarArray(vetorOriginal, vetorCopia, tamanho);
            inicio = clock();
            quickSort(vetorCopia, 0, tamanho - 1);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\nTempo QuickSort: %f segundos\n", tempo);
            break;

        case 2:
            copiarArray(vetorOriginal, vetorCopia, tamanho);
            inicio = clock();
            mergeSort(vetorCopia, 0, tamanho - 1);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\nTempo MergeSort: %f segundos\n", tempo);
            break;

        case 3:
            copiarArray(vetorOriginal, vetorCopia, tamanho);
            inicio = clock();
            insertionSort(vetorCopia, tamanho);
            fim = clock();
            tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
            printf("\nTempo InsertionSort: %f segundos\n", tempo);
            break;
            
		case 4:
			copiarArray(vetorOriginal, vetorCopia, tamanho);
    		inicio = clock();
    		bubbleSort(vetorCopia, tamanho);
    		fim = clock();
    		tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    		printf("\nTempo BubbleSort: %f segundos\n", tempo);
    		break;
    		
    	case 5:
		    copiarArray(vetorOriginal, vetorCopia, tamanho);
		    inicio = clock();
    		selectionSort(vetorCopia, tamanho);
    		fim = clock();
    		tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    		printf("\nTempo SelectionSort: %f segundos\n", tempo);
    		break;
    		
        case 6:
            printf("\nExecutando todos os algoritmos...\n");

            // Quick
            copiarArray(vetorOriginal, vetorCopia, tamanho);
            inicio = clock();
            quickSort(vetorCopia, 0, tamanho - 1);
            fim = clock();
            printf("QuickSort: %f segundos\n",
                   (double)(fim - inicio) / CLOCKS_PER_SEC);

            // Merge
            copiarArray(vetorOriginal, vetorCopia, tamanho);
            inicio = clock();
            mergeSort(vetorCopia, 0, tamanho - 1);
            fim = clock();
            printf("MergeSort: %f segundos\n",
                   (double)(fim - inicio) / CLOCKS_PER_SEC);

            // Insertion
            copiarArray(vetorOriginal, vetorCopia, tamanho);
            inicio = clock();
            insertionSort(vetorCopia, tamanho);
            fim = clock();
            printf("InsertionSort: %f segundos\n",
                   (double)(fim - inicio) / CLOCKS_PER_SEC);
                   
            // Bubble
			copiarArray(vetorOriginal, vetorCopia, tamanho);
			inicio = clock();
			bubbleSort(vetorCopia, tamanho);
			fim = clock();
			printf("BubbleSort: %f segundos\n",
					(double)(fim - inicio) / CLOCKS_PER_SEC);

			// Selection
			copiarArray(vetorOriginal, vetorCopia, tamanho);
			inicio = clock();
			selectionSort(vetorCopia, tamanho);
			fim = clock();
			printf("SelectionSort: %f segundos\n",
					(double)(fim - inicio) / CLOCKS_PER_SEC);

            break;

        case 0:
            printf("Encerrando programa.\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
