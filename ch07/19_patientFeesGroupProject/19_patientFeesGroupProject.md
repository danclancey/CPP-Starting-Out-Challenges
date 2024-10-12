# Patient Fees Group Project
Write a program that computes a patient’s bill for a hospital stay. The different 
components of the program are

- The PatientAccount class, which will keep a total of the patient’s charges. It will 
      also keep track of the number of days spent in the hospital. The group must decide on 
      the hospital’s daily rate.

- The Surgery class, which will have stored within it the charges for at least five 
      types of surgery. It can update the charges variable of the PatientAccount class.

- The Pharmacy class, which will have stored within it the price of at least five types of 
      medication. It can update the charges variable of the PatientAccount class.

- The client program (i.e., the main program).

Divide the work so that each student is given about the same workload. For example, one or two 
students might design the client program, while other individuals or pairs design each class it 
will use. Then, before beginning to write any code, the group should decide on function names, 
parameters, and return types so all the completed modules will properly work together when they 
are combined into the final program.

The main program should include a menu that allows the user to enter a type of surgery, enter one 
or more types of medication, and check the patient out of the hospital. When the patient checks 
out, the total charges should be displayed.
*/

## Structure of program 

### Classes

#### PatientAccount 
- **Constructor**:
    - totalCharges = 0.0
    - daysInHospital = 0.0

- **Private Variables**:
    - `double totalCharges`
    - `int daysInHospital`
    - `double dailyRate`

- **Public Functions**:
    - `void addCharges(double amt)`
    - `void setDaysInHospital(int days)`
    - `void getTotalCharges() const`

#### Surgery 
- **Constructor**:
    - `minorSurgery = 1500.00`
    - `majorSurgery = 2500.00`
    - `emergencySurgery = 3000.00`
    - `electiveSurgery = 4500.00`
    - `cosmeticSurgery = 5000.00`

- **Private Variables**:
    - `double minorSurgery`
    - `double majorSurgery`
    - `double emergencySurgery`
    - `double electiveSurgery`
    - `double cosmeticSurgery`

- **Public Functions**:
    - `void applySurgery(PatientAccount account, int surgeryType)`

#### Pharmacy 
- **Constructor**:
    - `medA = 50.00`
    - `medB = 75.00`
    - `medC = 100.00`
    - `medD = 125.00`
    - `medE = 150.00`

- **Private Variables**:
    - `double medA`
    - `double medB`
    - `double medC`
    - `double medD`
    - `double medE`

- **Public Functions**:
    - `void addMedication(PatientAccount &account, int medType)`

### Client Code 
#### Required Objects
- `PatientAccount patient`
- `Surgery surgery`
- `Pharmacy pharmacy`

#### Variables 
- `int days, surgeryType, medType`
- `char choice`


#### Program flow
1. Prompt user for number of days in hospital 
    - Store input in `days`
    - Validate input                        
    - pass to `patient.setDaysInHospital`

2. Prompt for Surgery type 
    - Store input in `surgeryType`
    - Validate input                       
    - pass to `surgery.applySurgery`

3. Loop for medication slection
    - Initial list for meds
        - store in `medType`
        - Validate input                  
        - pass to `pharmacy.addMedication`
        - Ask to add additional meds (y/n) `char choice`
        - Validate input                 

4. Display total Charges `patient.getTotalCharges`
    
