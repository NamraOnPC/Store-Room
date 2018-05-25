var patient = {

    pid: 1001,
    name: 'Keith',
    ward: 'HDU',
    //getters
    getpid: function(){return this.pid;},
    getname: function(){return this.name;},
    getward: function(){return this.ward;},
    //setters
    setpid: function(newpid){this.pid = newpid},
    setname: function(newname){this.name = newname},
    setward: function(newward){this.ward = newward}
};


patient.setpid(1002);
patient.setname('Smith');
patient.setward('ICU');

console.log(patient.getpid());
console.log(patient.getname());
console.log(patient.getward());


/*
console.log(patient.pid);
console.log(patient.name);
console.log(patient.ward);
*/

var patient2 = Object.create(patient);

console.log(patient2.getpid());
console.log(patient2.getname());
console.log(patient2.getward());
